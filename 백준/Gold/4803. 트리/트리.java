import java.util.*;
import java.lang.*;
import java.io.*;

// 정점 N - 1 =  간선 개수 
// 정점으로 일단 순회 
// 만약 visited 정점이라면 continue
// 해당 정점으로 돌았을 때 트리라면?(순환하지 않는다면) ++ 
// 아니라면 - 
class Main {
    
    private static Map<Integer, List<Integer>> nodes;
    private static int N, M;
    private static boolean[] visited;
    private static boolean isCircle;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        int caseCount = 0;
        while(true) {
            caseCount++;
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            if(N == 0 && M == 0) break;
            
            nodes = new HashMap<>();
            for(int i = 1; i <= N; i++) {
                nodes.put(i, new ArrayList<>());
            }
            
            for(int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                nodes.get(start).add(end);
                nodes.get(end).add(start);
            }

            int treeCount = 0;
            visited = new boolean[N+1];
            for(int i = 1; i <= N; i++){
                if(visited[i]) continue;
                
                isCircle = false; 
                findTree(i, -1);
                if(!isCircle) treeCount++;
            }   

            if(treeCount > 1) {
                System.out.println("Case " + caseCount + ": A forest of " + treeCount + " trees.");
            }
            else if(treeCount == 1) {
                System.out.println("Case " + caseCount + ": There is one tree.");
            }
            else if(treeCount == 0) {
                System.out.println("Case " + caseCount + ": No trees.");
            }
        }
    }
    
    private static void findTree(int now, int prev) {
        visited[now] = true;

        for(int next : nodes.get(now)) {  
            
            if(next == prev) continue;
            
            if(visited[next]) {
                isCircle = true;
                continue;
            } 
            
            findTree(next, now);
        }
    }
}