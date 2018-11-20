#pragma once
#include <iostream>

template <class TYPE>
class ListT
{
public:

	template <class TYPE2>
	class Element
	{
	private:
		Element<TYPE2>* pNext;
		Element<TYPE2>* pPrev;
		TYPE2 pInf;

	public:
		Element() { pNext = NULL; pInf = NULL; pPrev = NULL; }

		void setNext(Element<TYPE2>* next) { pNext = next; }
		Element<TYPE2>* getNext() { return pNext; }

		void setPrev(Element<TYPE2>* prev) { pPrev = prev; }
		Element<TYPE2>* getPrev() { return pPrev; }

		void setInf(TYPE2 inf) { pInf = inf; }
		TYPE2 getInf() { return pInf; }
		
	};

	ListT();
	~ListT();
	void InitializeListT();
	void include(TYPE inf);
	void clear();
	void remove(Element<TYPE>* pAux);

	Element<TYPE>* getpFirst() { return pFirst; }
	const Element<TYPE>* getpCurr() const { return pCurr; }

private:
	Element<TYPE>* pFirst;
	Element<TYPE>* pCurr;
};

template<class TYPE>
ListT<TYPE>::ListT()
{
	InitializeListT();
}

template<class TYPE>
ListT<TYPE>::~ListT()
{
	clear();
}

template<class TYPE>
void ListT<TYPE>::InitializeListT()
{
	pFirst = NULL;
	pCurr = NULL;
}

template<class TYPE>
void ListT<TYPE>::include(TYPE inf)
{
	//if (inf != NULL)
	//{
		Element<TYPE>* pAux = new Element<TYPE>;
		pAux->setInf(inf);

		if (pFirst == NULL)
		{
			pFirst = pAux;
			pCurr = pAux;
		}

		else
		{
			pAux->setNext(NULL);
			pCurr->setNext(pAux);
			pAux->setPrev(pCurr);
			pCurr = pCurr->getNext();
		}
	//}
}

template<class TYPE>
void ListT<TYPE>::clear()
{
	Element<TYPE>* pAux1;
	Element<TYPE>* pAux2;

	pAux1 = pFirst;
	pAux2 = pAux1;

	while (pAux1 != NULL)
	{
		pAux2 = pAux1->getNext();
		delete pAux1;
		pAux1 = pAux2;
	}

	pFirst = NULL;
	pCurr = NULL;
}

template<class TYPE>
inline void ListT<TYPE>::remove(Element<TYPE>* pAux)
{
	Element<TYPE>* paux0 = pFirst;
	Element<TYPE>* paux1 = paux0;

	if (pAux == pCurr)
	{
		if (pAux != pFirst)
			pCurr = pCurr->getPrev();
	}
	if (pAux != pFirst)
	{

		while (paux1 != pAux)
		{
			paux0 = paux1;
			paux1 = paux1->getNext();
		}

		paux0->setNext(paux1->getNext());
		pAux->getNext()->setPrev(paux0);
		delete paux1;
	}
	else
		delete pFirst;
}
