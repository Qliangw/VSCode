#include "myStack.h"
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
};

struct status {
    point pt;
    int direction; //以direction取值0,1,2,3标记东南西北
};

void maze_with_stack()
{
    const int m = 5;
    const int n = 7;
    const char unvisited = '0';
    const char visited   = 'V';

    char maze[m][n] = {
        {'*', '*', '*', '*', '*', '*', '*'},
        {'*', '0', '*', '0', '0', '0', '*'},
        {'*', '0', '*', '0', '*', '0', '*'},
        {'*', '0', '0', '0', '*', '0', '*'},
        {'*', '*', '*', '*', '*', '*', '*'},
    };

    const int d = 4; //可行方向总数
    //以下标取值0,1,2,3标记东南西北与当前位置的偏移量
    const point delta[d] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    //起点与终点的坐标
    point source = {1, 1};
    point destination = {3, 5};

    vector<status> path;                // 搜索时保留路径所用的向量, 可视为栈.
    path.reserve(m * n);                // 提前预留容量.
    path.push_back({source,0});         // 初始点设为入口点, 并设定初始方向.
    maze[source.x][source.y] = visited;
    while(!path.empty())
    {
        if (path.back().direction < d)  //当前 path.back().direction 相当于栈顶
        {
            point next = {path.back().pt.x + delta[path.back().direction].x,
                          path.back().pt.y + delta[path.back().direction].y};
            ++path.back().direction;
            if (maze[next.x][next.y] == unvisited)
            {
                maze[next.x][next.y] = visited;
                path.push_back({next, 0});
                //放到路径向量后再判断该点是否为终点并及时跳出循环
                if(next.x == destination.x && next.y == destination.y)
                    break;
            }
        }
        else
            path.pop_back();
    }

    for(const auto& c : path)
        cout << c.pt.x << ' ' << c.pt.y << endl;

}