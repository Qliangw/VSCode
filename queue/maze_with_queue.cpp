#include <iostream>
#include "myQueue.h"

using namespace std;

//�ݲ�����point�����(==)�Ͳ����(!=)�����
struct point{
    int x;
    int y;
};

struct status{
    point pt;
    size_t level;
};

int maze_with_queue()
{
    const int m = 5;
    const int n = 7;
    const char unvisited = '0';     //δ���ʹ��ı��
    const char visited = 'V';       //���ʹ��ı��

    //�Թ��ַ����飬��ΧһȦȫ��ǽ(��'*'���)
    char maze[m][n] = {
        {'*', '*', '*', '*', '*', '*', '*'},
        {'*', '0', '*', '0', '0', '0', '*'},
        {'*', '0', '*', '0', '*', '0', '*'},
        {'*', '0', '0', '0', '*', '0', '*'},
        {'*', '*', '*', '*', '*', '*', '*'},
    };

    const int d = 4;        // ���з�������

    //���±�ȡֵ0��1,2,3��Ƕ��������뵱ǰλ�õ�ƫ����
    const point delta[d] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    //������յ������
    point source = {1,1};
    point destination = {3,5};
    point parent[m][n];
    queue<status> Q;        // ����ʱ���ö���
    vector<point> P;        // ��������·��
    Q.push({destination,0});//��ʼ����Ϊ���ڵ㲢�ƶ���ʼ���
    maze[destination.x][destination.y] = visited;
    while(!Q.empty())
    {
        for(int direction = 0; direction < d; ++direction)
        {
            point neighbor = {Q.front().pt.x + delta[direction].x,
                              Q.front().pt.y + delta[direction].y};
            if (maze[neighbor.x][neighbor.y] == unvisited)
            {
                parent[neighbor.x][neighbor.y] = Q.front().pt;
                if(neighbor.x == source.x && neighbor.y == source.y)
                {
                    //��ǰԤ���ռ䣬��ȻҲ���Բ��ñ��浽P�У�ֱ����parent���ݴ�ӡ
                    P.reserve(Q.front().level + 2);
                    P.push_back(source);
                    while(P.back().x != destination.x || P.back().y != destination.y)
                        P.push_back(parent[P.back().x][P.back().y]);
                    for(const auto& c: P)
                        cout << c.x << ' ' << c.y << endl;
                    
                    //���ʹ��break���ֻ��������ǰforѭ������Ҫ���ñ�Ǳ����������whileѭ��
                    //����ֱ�ӷ��ؽ�����������
                    return 0;
                }
                maze[neighbor.x][neighbor.y] = visited;
                Q.push({neighbor, Q.front().level + 1});
            }
        }
        Q.pop();
    }
    return 0;
}
