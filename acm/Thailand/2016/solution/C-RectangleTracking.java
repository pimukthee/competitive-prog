import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class C_RectangleTracking_OK {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		while(t-->0){
			int n = sc.nextInt();
			char pic[][] = new char[n][n];
			boolean isKeepA = false;
			int r = 0;
			int c = 0;
			for (int i = 0; i < pic.length; i++) {
				String line = sc.next();
				pic[i] = line.toCharArray();
				if(line.contains("#") && !isKeepA){
					r = i;
					c = line.indexOf('#');
					isKeepA = true;
				}
			}
			
			ArrayList<String> corner = DFS_FindCorner(pic,r,c);
			System.out.println(countBox(corner, pic));
		}
		
		
	}
	
	static String countBox(ArrayList<String> corner, char ch[][]){
		int countSqre = 0;
		int countRect = 0;
		
		String strCorner = "";
		for (int i = 0; i < corner.size(); i++) 
			strCorner += "["+corner.get(i)+"] ";
		strCorner = strCorner.trim();
		
		String sCorner[] = strCorner.split(" ");
		for (int i = 0; i < sCorner.length; i++) {
			for (int j = i+1; j < sCorner.length; j++) {
				String u[] = sCorner[i].split(",");
				int ur = Integer.parseInt(u[0].replace("[", ""));
				int uc = Integer.parseInt(u[1].replace("]", ""));
				
				String v[] = sCorner[j].split(",");
				int vr = Integer.parseInt(v[0].replace("[", ""));
				int vc = Integer.parseInt(v[1].replace("]", ""));
				
				int dr = vr-ur;
				int dc = vc-uc;
				if(dr<0 || (dr==0 && dc<0)){
					String temp = sCorner[i];
					sCorner[i] = sCorner[j];
					sCorner[j] = temp;
				}
			}
		}
		
		ArrayList<String> cornR = new ArrayList<String>();
		ArrayList<String> cornD = new ArrayList<String>();
		for (int i = 0; i < sCorner.length; i++) {
			String u[] = sCorner[i].split(",");
			String uR = u[0];
			String uD = u[1];
			int ru = Integer.parseInt(uR.replace("[", ""));
			int cu = Integer.parseInt(uD.replace("]", ""));
			cornR.clear();
			cornD.clear();
			for (int j = i+1; j < sCorner.length; j++) {
				int r = 0;
				int c = 0;
				int len = 0;
				int count = 0;
				if(sCorner[j].contains(uR+",")){
					String split[] = sCorner[j].split(",");
					r = Integer.parseInt(split[0].replace("[", ""));
					c = Integer.parseInt(split[1].replace("]", ""));
					len = c-cu;
					count = 0;
					while(c-->cu+1){
						if(ch[r][c]!='#')
							break;
						count++;
					}
					if(count==len-1)
						cornR.add(sCorner[j]);
				}
				if(sCorner[j].contains(","+uD)){
					String split[] = sCorner[j].split(",");
					r = Integer.parseInt(split[0].replace("[", ""));
					c = Integer.parseInt(split[1].replace("]", ""));
					len = r-ru;
					count = 0;
					while(r-->ru+1){
						if(ch[r][c]!='#')
							break;
						count++;
					}
					if(count==len-1)
						cornD.add(sCorner[j]);
				}
			}
			for (int j = 0; j < cornR.size(); j++) {
				String v[] = cornR.get(j).split(",");
				String vD = v[1];
				for (int k = 0; k < cornD.size(); k++) {
					v = cornD.get(k).split(",");
					String vR = v[0];
					
					String lastCorn = vR+","+vD;
					int count = 0;
					if(strCorner.contains(lastCorn)){
						int r1 = Integer.parseInt(uR.replace("[", ""));
						int c1 = Integer.parseInt(uD.replace("]", ""));
						int r2 = Integer.parseInt(vR.replace("[", ""));
						int c2 = Integer.parseInt(vD.replace("]", ""));
						
						int dr = r2-r1;
						int dc = c2-c1;
						
						count = 0;
						int tmp = c2;
						while(tmp-->c1+1){
							if(ch[r2][tmp]!='#')
								break;
							count++;
						}
						if(count!=dc-1)
							continue;
						
						count = 0;
						tmp = r2;
						while(tmp-->r1+1){
							if(ch[tmp][c2]!='#')
								break;
							count++;
						}
						if(count!=dr-1)
							continue;
						
						if(dr==dc)
							countSqre++;
						else
							countRect++;
						
					}
						
				}
			}
		}
		
		return (countSqre+countRect)+" "+countSqre+" "+countRect;
	}
	
	static ArrayList<String> DFS_FindCorner(char ch[][], int r, int c){
		int n = ch.length;
		char pic[][] = new char[n][n];
		for (int i = 0; i < pic.length; i++) {
			for (int j = 0; j < pic.length; j++) {
				pic[i][j] = ch[i][j];
			}
		}
		ArrayList<String> corner = new ArrayList<String>(); 
		
		LinkedList<RC> stack = new LinkedList<RC>();
		stack.push(new RC(r,c));
		
		while(!stack.isEmpty()){
			RC u = stack.pop();
			r = u.r;
			c = u.c;
			
			//4 Direction
			int up = r-1;
			int down = r+1;
			int left = c-1;
			int right = c+1;
			
			if(up>=0){
				if(pic[up][c]=='#'){
					stack.push(new RC(up,c));
					pic[up][c] = 'V'; //Visited
				}
				//Check corner
				if(ch[up][c]=='#' && 
						((left>=0 && ch[r][left]=='#') ||
								(right<n && ch[r][right]=='#'))){
					if(!corner.contains(r+","+c))
						corner.add(r+","+c);
				}
			}
			
			if(down<n){
				if(pic[down][c]=='#'){
					stack.push(new RC(down,c));
					pic[down][c] = 'V'; 
				}
				
				if(ch[down][c]=='#' &&
						((left>=0 && ch[r][left]=='#') ||
							(right<n && ch[r][right]=='#'))){
					if(!corner.contains(r+","+c))
						corner.add(r+","+c);
				}
			}
			
			if(left>=0){
				if(pic[r][left]=='#'){
					stack.push(new RC(r,left));
					pic[r][left] = 'V'; 
				}
				
				if(ch[r][left]=='#' &&
						((up>=0 && ch[up][c]=='#') ||
								(down<n && ch[down][c]=='#'))){
					if(!corner.contains(r+","+c))
						corner.add(r+","+c);
				}
			}
			
			if(right<n){
				if(pic[r][right]=='#'){
					stack.push(new RC(r,right));
					pic[r][right] = 'V'; 
				}
				
				if(ch[r][right]=='#' &&
						((up>=0 && ch[up][c]=='#') ||
								(down<n && ch[down][c]=='#'))){
					if(!corner.contains(r+","+c))
						corner.add(r+","+c);
				}
			}
			
		}
		
		return corner;
	}
	
	static class RC{
		int r;
		int c;
		
		public RC(int r, int c){
			this.r = r;
			this.c = c;
		}
	}

}
