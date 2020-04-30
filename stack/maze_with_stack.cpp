#include "myStack.h"
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
};

struct status {
    point pt;
    int direction; //��directionȡֵ0,1,2,3��Ƕ�������
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

    const int d = 4; //���з�������
    //���±�ȡֵ0,1,2,3��Ƕ��������뵱ǰλ�õ�ƫ����
    const point delta[d] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    //������յ������
    point source = {1, 1};
    point destination = {3, 5};

    vector<status> path;                // ����ʱ����·�����õ�����, ����Ϊջ.
    path.reserve(m * n);                // ��ǰԤ������.
    path.push_back({source,0});         // ��ʼ����Ϊ��ڵ�, ���趨��ʼ����.
    maze[source.x][source.y] = visited;
    while(!path.empty())
    {
        if (path.back().direction < d)  //��ǰ path.back().direction �൱��ջ��
        {
            point next = {path.back().pt.x + delta[path.back().direction].x,
                          path.back().pt.y + delta[path.back().direction].y};
            ++path.back().direction;
            if (maze[next.x][next.y] == unvisited)
            {
                maze[next.x][next.y] = visited;
                path.push_back({next, 0});
                //�ŵ�·�����������жϸõ��Ƿ�Ϊ�յ㲢��ʱ����ѭ��
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