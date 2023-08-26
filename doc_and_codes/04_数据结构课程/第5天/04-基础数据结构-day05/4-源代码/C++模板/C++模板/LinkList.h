#pragma  once

// 节点结构
template <typename T>
struct ListNode
{
	// 数据域
	T data;
	// 指针域
	ListNode *next;
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	// 插入
	void insert(int pos, T &data);
	// 删除
	T del(int pos);
	// 获取指定位置
	T get(int pos);
	// 清空
	void clear();
	// 获取长度
	int length();

private:
	// 头结点
	ListNode<T> *m_head;
	// 长度
	int m_length;
};