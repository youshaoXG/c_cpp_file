#pragma  once

// �ڵ�ṹ
template <typename T>
struct ListNode
{
	// ������
	T data;
	// ָ����
	ListNode *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	// ����
	void insert(int pos, T &data);
	// ɾ��
	T del(int pos);
	// ��ȡָ��λ��
	T get(int pos);
	// ���
	void clear();
	// ��ȡ����
	int length();

private:
	// ͷ���
	ListNode<T> *m_head;
	// ����
	int m_length;
};