m, n = map(int, input().split())
maps = [input() for _ in range(m)]
x, y = map(int, input().split())
t = int(input())

move = [list(map(int, input().split())) for _ in range(t)]
visit = [[True if maps[i][j] == '.' else False for j in range(n)] for i in range(m)]

N = sum(1 if visit[i][j] else 0 for i in range(m) for j in range(n))


def layer():
    if maps[x][y] == 'X':
        return -1
    result, count = 1, 1
    visit[x][y] = False
    que = [[x, y]]
    while que:
        tmp = []
        for i, j in que:
            for ax, ay in move:
                nx, ny = ax + i, ay + j
                if 0 <= nx < m and 0 <= ny < n and maps[nx][ny] == '.' and visit[nx][ny]:
                    tmp.append([nx, ny])
                    visit[nx][ny], count = False, count + 1
                if count == N: return result
        que, result = tmp, result + 1
    return -1


print(layer())
