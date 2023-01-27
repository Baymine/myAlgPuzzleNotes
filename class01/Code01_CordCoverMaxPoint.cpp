#include <vector>

//using namespace std;
/** 
题目描述：给定一个有序数组arr，代表坐落在X轴上的点，给定一个正数K，代表绳子的长度，返回绳子最多压中几个点？  
即使绳子边缘处盖住点也算盖住

算法思路：
1) 贪心思想。
    以当前节点结尾的能够覆盖的最多的节点个数。
    这个节点个数可以通过二分查找的方法得出
    时间复杂度：nlog(n)

2) 滑动窗口+双指针
    以当前节点为起始(使用双指针标识起始位置)，能够覆盖的最多的元素
    时间复杂度：n
*/


class Code01_CordCoverMaxPoint{
    /** Method 1
    1) 贪心思想。
        以当前节点结尾的能够覆盖的最多的节点个数。
        这个节点个数可以通过二分查找的方法得出
        时间复杂度：nlog(n)
     */
    int maxPoint1(std::vector<int>&arr, int L){
        int res = 1;
        for(int i = 0; i < arr.size(); ++i){
            // arr[i] - L: 以i为终点所能达到的最远距离
            int nearest = nearestIndex(arr, i, arr[i] - L);
            res = std::max(res, i - nearest + 1);
        }
        return res;
    }

    // 找到arr中第一个大于value的位置
    int nearestIndex(std::vector<int>& arr, int right, int value){
        int left = 0, index = right;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if(arr[mid] >= value){
                right = mid - 1; index = mid;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }
    /* end of Method 1*/

    /**
     * Method 2： 滑动窗口+双指针
     */
    int maxPoint2(std::vector<int>& arr, int L){
        int left = 0, right = 0;
        int res = 0;

        for(int i = 0; i < arr.size(); ++i){
            while(right < arr.size() && arr[right] - arr[left] <= L) right++;
            res = std::max(res, right-(left++));
        }
        return res;
    }
};