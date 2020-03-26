# LCA

- 부모 정보와 깊이 정보를 미리 기록해둔다.
- **depth[i]** : i번 노드의 깊이
- **p[i][j]** : i번 노드의 2^j 번째 조상
- **p[i][j] = p[p[i][j - 1]][j - 1]**
```c
int lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y); // depth x < y

	for (int i = 14; i >= 0; i--) // 시작 값은 전체 노드수에 따라 변화. 2^14면 노드 10000개 커버.
		if (depth[x] <= depth[p[y][i]])
			y = p[y][i]; // depth 같게 맞추기


	if (x == y) // 부모가 같아졌으면 바로 return
		return x;
	
	for (int i = 14; i >= 0; i--)
		if (p[x][i] != p [y][i]) x = p[x][i], y = p[y][i];

	return p[x][0]; // x,y의 
}
```
