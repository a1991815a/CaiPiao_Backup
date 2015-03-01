#ifndef __Formula__
#define __Formula__
#include "Element.h"

struct  Lotter;

class FormulaBase:public Element{
	friend class Formula_1;
public://���캯��
	INIT_STRUCT(FormulaBase, Element);

public://�����º���
	~FormulaBase(){ clear(); };
	
	int IndexOf(Element*) const;
	void push_back(Element*);
	void insertEle(Element*,int);
	void removeEle(int);
	void removeEle(Element*);
	Element* at(int) const;
	int getListLength() const;
	bool isEmpty() const;
	bool containsEle(Element*) const;
	void clear();
	inline QList<Element*> getList() const { return formula_list; }
	

protected:
	inline QVector<Element*> getVector() const { return formula_list.toVector(); }
private:
	QList<Element*> formula_list;
};

class MathSignal:public Element{
public://���캯��
	INIT_STRUCT(MathSignal, Element);
public://�����º���
	void MergeLeft(int);
	void MergeRight(int);
	void MergeDouble(int);
	
public:
	static Element* RandGenerate(Element*);

};

class MathNumber:public Element{
public://���캯��
	INIT_STRUCT(MathNumber, Element);
public://�����º���
	virtual void init()override{ setPriority(NumberPrority); };

	virtual void Calculate(DataType) override;
	static Element* RandGenerate();

	virtual inline int getValue() const override{ return getText().toInt(); };

	static QVector<QString> getSignal(){ return _signal; };
	
private://����
	static QVector<QString> _signal;

};

class Formula:public FormulaBase{

public://���캯��
	INIT_STRUCT(Formula, FormulaBase);
public://�����º���
	virtual void init() override { setPriority(FormulaPrority); };
	virtual QString getText() const override;
	void setHighestParent();

	virtual void Parse() override;
	virtual void Calculate(DataType) override;

	static Element* RandGenerate(int);
	static Element* RandGenerate(int, Formula*);

	static QVector<QString> getSignal(){ return _signal; };

public:
	void clearCalculatePoor();
	QList<Element*> CalculatePoor;

private://����
	static QVector<QString> _signal;

	void CalcualteByPriorty(int,DataType);

};

class MathSignal_1 :public MathSignal{
public://���캯��
	INIT_STRUCT(MathSignal_1, MathSignal);
public://�����º���
	virtual void init() override { setPriority(Signal_1_Prority); };
	virtual void Calculate(DataType) override;
	static Element* RandGenerate(Formula*);
	static Element* RandGenerate();

	static QVector<QString> getSignal(){ return _signal; };
private://����
	static QVector<QString> _signal;

};

class MathSignal_2 :public MathSignal{
public://���캯��
	INIT_STRUCT(MathSignal_2, MathSignal);
public://�����º���
	virtual void init() override { setPriority(Signal_2_Prority); };
	virtual void Calculate(DataType) override;
	static Element* RandGenerate(Formula*);
	static Element* RandGenerate();

	static QVector<QString> getSignal(){ return _signal; };
private://����
	static QVector<QString> _signal;

};

class MathSignal_3 :public MathSignal{
public://���캯��
	INIT_STRUCT(MathSignal_3, MathSignal);
public://�����º���
	virtual void init() override { setPriority(Signal_3_Prority); };
	virtual void Calculate(DataType) override;
	static Element* RandGenerate(Formula*);
	static Element* RandGenerate();

	static QVector<QString> getSignal(){ return _signal; };
private://����
	static QVector<QString> _signal;

};

class MathSignal_4 :public MathSignal{
public://���캯��
	INIT_STRUCT(MathSignal_4, MathSignal);
public://�����º���
	virtual void init() override { setPriority(Signal_4_Prority); };
	virtual void Calculate(DataType) override;
	static Element* RandGenerate(Formula*);
	static Element* RandGenerate();

	static QVector<QString> getSignal(){ return _signal; };
private://����
	static QVector<QString> _signal;
};

class LotterTag: public Element{
public://���캯��
	INIT_STRUCT(LotterTag, Element);
public://�����º���
	virtual int getValue(int) const = 0;
	virtual int getValue(Lotter)const = 0;
	virtual void init() override { setPriority(MathTagPrority); };
	virtual void Calculate(DataType) override;
	static Element* RandGenerate(Formula*);
	
	static QVector<QString> getSignal(){ return _signal; };
private://����
	static QVector<QString> _signal;

public:
	virtual inline int getMaxValue() const { return _max; }
	virtual inline int getMinValue() const { return _min; }
protected: //����ͨ������
	int _min, _max;
};


#endif