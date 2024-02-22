#include <stdio.h>
#include <queue>
#include <assert.h>
using namespace std;
struct Node
{
  double nValue;
  double nWeight;
  double nUpbound;
  double nIndex;
};

class PriceCmp
{
    public:
    bool operator()(Node& dataFst_, Node& dataSec_)
    {
        return dataFst_.nValue > dataSec_.nValue;
    }
};

// 获取最优价值的放置方法
double BranchAndBound(vector<double> vecWeight_, vector<double> vecValue_, double nCapacity)
{

    double _nBestValue = 0.0; // 搜索过程中的最优价值
    priority_queue<Node, vector<Node>, PriceCmp> _priorityQueue; // 默认是是vector，less
    queue<Node> _queue;
    // level 放入物品的个数
    int _nlevel= 1;
    while(_nlevel <= vecWeight_.size())
    {
        // 物品索引号
        int  _nIndex = _nlevel - 1;
        if(_queue.empty())
        {
            // 记录求解状态，暂不进行价值优化
            if(vecWeight_[_nIndex] <= nCapacity)
            {
                Node _CurNode;
                _CurNode.nWeight = vecWeight_[_nIndex];
                _CurNode.nValue = vecValue_[_nIndex];
                _nBestValue = max(_nBestValue, _CurNode.nValue);
                _queue.push(_CurNode);
            }
            else
                continue;
        }
        else
        {
            int _nCurSize = _queue.size();
            for(int i = 0; i < _nCurSize; i++)
            {
                Node _aliveNode = _queue.front();
                // 左子树
                if(_aliveNode.nWeight + vecWeight_[_nIndex] <= nCapacity)
                {
                    Node _leftNode;
                    _leftNode.nWeight = _aliveNode.nWeight + vecWeight_[_nIndex];
                    _leftNode.nValue = _aliveNode.nValue + vecValue_[_nIndex];
                    _nBestValue = max(_nBestValue, _leftNode.nValue);
                    _queue.push(_leftNode);
                }
                
                // 右子树
                Node _rightNode;
                _rightNode.nWeight = _aliveNode.nWeight;
                _rightNode.nValue = _aliveNode.nValue;
                _queue.push(_rightNode);
                
                // 消活当前节点
                _queue.pop();
            }
            
        }
        
        _nlevel ++;
    }
    
    return _nBestValue;
}
