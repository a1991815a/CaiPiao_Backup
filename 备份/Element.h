#ifndef __Element__
#define __Element__
#include <QtCore>
#include "CustomDefine.h"

class Formula;

#define INIT_STRUCT(A,B)				\
A(){init();};									\
A(QString text):B(text){init();};		\
A(QString text, Formula* parent):B(text,parent){init();}

class Element{
	friend class Formula;
public:
	enum DataType
	{
		DataMin,DataNormal,DataMax
	};
protected://���캯��
	Element();
	Element(QString);
	Element(QString, Formula*);

public://�ӿں���
	virtual void Parse(){};
	virtual void Calculate(DataType) = 0;
	virtual void init(){};

public://getter,setter����
	virtual inline QString getText() const { return _text; }
	inline void setText(QString val) { _text = val; }
	inline Formula* getParent() const { return _parent; }
	void setParent(Formula*);
	void insertBefore(Element*);
	void insertLast(Element*);

	void setParentDetach(Formula* val);
	virtual inline int getValue()const { return _value; };

	Element* getLeftElement() const;
	Element* getRightElement() const;
	Element* getLeftEleFromPoor();
	Element* getRightEleFromPoor();

protected://����ʹ�÷���
	inline void setPriorty(int val) { priorty = val; }
	inline void setValue(int val){ _value = val; };
	inline void setPriority(int priorty){ _priorty = priorty; };
	inline int getPriority(){ return _priorty; };

private://����
	int _priorty;
	QString _text;
	int priorty;
	int _value;
	Formula* _parent;
};
#endif
