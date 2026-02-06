#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

struct Node {
    char name[7];
    int parent; // 부모 노드 인덱스
    int firstChild; // 첫번째 자식 노드 인덱스
    int nextSibling; // 옆에 있는 형제 노드 인덱스
    int childCount; // 하위 모든 디렉터리의 총 개수
};

Node pool[50005]; // 전체 노드 저장소
int freeStack[50005]; // 사용 가능한 인덱스들이 들어있음
int top; // 보관함에 데이터가 어디까지 차 있는지를 가리킴


// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.

int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}


void init(int n) {
    // 1. 보관함 비우기
    top = 0;
    // 2. 0번부터 n-1번까지의 인덱스를 보관함에 모두 집어넣기, 거꾸로 넣어야 0번부터 꺼내 쓰기 편함
    for (int i = n - 1; i >= 0; i--) 
        freeStack[top++] = i;

    // 3. root 노드 생성
    int rootIdx = freeStack[--top]; // 가장 위에 있는 번호(0)을 꺼냄
    mstrcpy(pool[rootIdx].name, "/");
    pool[rootIdx].parent = -1;
    pool[rootIdx].firstChild = -1;
    pool[rootIdx].nextSibling = -1;
    pool[rootIdx].childCount = 0;
}

int find_node(const char* path) { // path 문자열을 해석해 해당 노드의 인덱스를 찾음
    int current = 0; // 루트부터 시작

    if (mstrcmp(path, "/") == 0) return current; // 만약 경로가 "/" 그 자체라면 바로 루트 인덱스 반환

    int cursor = 1;
    char tempName[7];

    while (path[cursor] != '\0') {

        int i = 0;
        while (path[cursor] != '\0' && path[cursor] != '/') {
            tempName[i++] = path[cursor++];
        }

        tempName[i] = '\0'; // 이름 완성
        if (path[cursor] == '/') cursor++; // 다음 탐색을 위해 '/' 건너뜀

        // 현재 current의 자식들 중에서 tempName과 일치하는 녀석 찾기
        int child = pool[current].firstChild;
        while (child != -1) {
            if (mstrcmp(pool[child].name, tempName)== 0) {
                current = child; break; // 일치하는 자식을 찾으면 그곳으로 이동
            }
            child = pool[child].nextSibling; // 옆 형제로 이동
        }
    }

    return current; // 최종 도착지의 인덱스 반환
}

void deallocate(int nodeIdx) {
    int curr = pool[nodeIdx].firstChild;
    while (curr != -1) {
        int next = pool[curr].nextSibling;
        deallocate(curr);
        curr = next;
    }
    freeStack[top++] = nodeIdx;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {

    int p = find_node(path);
    int idx = freeStack[--top];
    mstrcpy(pool[idx].name, name); pool[idx].parent = p; pool[idx].firstChild = -1; pool[idx].childCount = 0;
    pool[idx].nextSibling = pool[p].firstChild; // 노드 p의 자식 리스트 맨 앞에 M을 삽입
    pool[p].firstChild = idx;

    int curr = p;
    while (curr != -1) {
        pool[curr].childCount++;
        curr = pool[curr].parent; // 위로 한 단계 이동
    }
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {

    int target = find_node(path);
    int p = pool[target].parent;
    int curr = pool[p].firstChild;
    
    if (curr == target) { // 내가 부모의 첫번째 자식일때
        pool[p].firstChild = pool[target].nextSibling;
    }
    else { // target이 첫번째 자식이 아닐때,
        while (pool[curr].nextSibling != target) { // target의 앞 형제를 찾아야함
            curr = pool[curr].nextSibling;
        }
        pool[curr].nextSibling = pool[target].nextSibling;
    }

    int numToRemove = pool[target].childCount + 1;
    curr = p;
    while (curr != -1) {
        pool[curr].childCount -= numToRemove;
        curr = pool[curr].parent;
    }
    deallocate(target); // target과 그 하위 노드들을 전부 freeStack으로 반환

}

int deep_copy(int srcIdx, int dstIdx) {

    int newIdx = freeStack[--top];
    mstrcpy(pool[newIdx].name, pool[srcIdx].name); // 새로운 인덱스의 정보에 srcIdx의 정보를 복사
    pool[newIdx].parent = dstIdx;
    pool[newIdx].childCount = pool[srcIdx].childCount;

    // 자식과 형제의 관계는 그대로 가져오면 안됨
    pool[newIdx].firstChild = -1;
    pool[newIdx].nextSibling = -1;

    // 자식들을 하나하나 새로 만들어서 연결
    int srcChild = pool[srcIdx].firstChild; // 원본의 첫째 자식부터 시작
    while (srcChild != -1) {
        // 원본 첫째 자식의 자식이 똑같은 복사본을 만들어서 옴
        int newChildIdx = deep_copy(srcChild, newIdx);

        // 새로 태어난 쌍둥이 자식을 나의 자식 리스트에 연결
        pool[newChildIdx].nextSibling = pool[newIdx].firstChild;
        pool[newIdx].firstChild = newChildIdx;

        // 원본의 다음 동생으로 넘어가서 다음 과정을 반복
        srcChild = pool[srcChild].nextSibling;
    }
    return newIdx; // 완성된 복사본 번호 반환

}


void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {

    int s = find_node(srcPath);
    int d = find_node(dstPath);

    int newNodeIdx = deep_copy(s, d);

    pool[newNodeIdx].nextSibling = pool[d].firstChild;
    pool[d].firstChild = newNodeIdx;

    int addCount = pool[s].childCount + 1;
    int curr = d;
    while (curr != -1) {
        pool[curr].childCount += addCount;
        curr = pool[curr].parent;
    }

}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    int s = find_node(srcPath);
    int d = find_node(dstPath); // find node를 통해 src 경로와 dst 경로를 찾음

    int oldP = pool[s].parent;
    int curr = pool[oldP].firstChild;

    if (curr == s){ // s가 oldP의 첫번째 자식일떄,
        pool[oldP].firstChild = pool[s].nextSibling; // s를 원래 부모에서 끊어냄
    }
    else {
        while (pool[curr].nextSibling != s)
            curr = pool[curr].nextSibling; // s를 만날때까지 다음 형제를 반복문으로 순회
        pool[curr].nextSibling = pool[s].nextSibling;
    }

    int moveCount = pool[s].childCount + 1; // s의 부모들의 자식 갯수 갱신
    int temp = oldP;
    while (temp != -1) {
        pool[temp].childCount -= moveCount;
        temp = pool[temp].parent;
    }

    pool[s].parent = d; // s를 d의 자식으로 할당
    pool[s].nextSibling = pool[d].firstChild; // 원래의 첫번째 자식을 s의 다음 형제로 할당
    pool[d].firstChild = s; // s를 d의 첫번째 자식으로 할당

    temp = d;
    while (temp!= -1) {
        pool[temp].childCount += moveCount;
        temp = pool[temp].parent;
    }
}

int cmd_find(char path[PATH_MAXLEN + 1]) {

    int target = find_node(path);
	return pool[target].childCount;
}