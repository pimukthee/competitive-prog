import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

//Coding by Mr.Prapot Thumsiraruk
public class K_RubikNumber2D_VeryFast {
	
	static String correctHori[] = new String[3];
	static String correctVerti[] = new String[3];
	static String correctRubik = "123\n456\n789";
	static String pathName[] = new String[13];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//Initial Correct Board
		correctHori[0] = "123";
		correctHori[1] = "456";
		correctHori[2] = "789";
		correctVerti[0] = "147";
		correctVerti[1] = "258";
		correctVerti[2] = "369";
		
		//Initial Path Name
		pathName[1] = "1. Top Left";
		pathName[2] = "2. Top Right";
		pathName[3] = "3. Bottom Left";
		pathName[4] = "4. Bottom Right";
		pathName[5] = "5. Middle Swap Hori";
		pathName[6] = "6. Middle Swap Verti";
		pathName[7] = "7. Left Up";
		pathName[8] = "8. Left Down";
		pathName[9] = "9. Right Up";
		pathName[10] = "10. Right Down";
		pathName[11] = "11. Counter-Clockwise";
		pathName[12] = "12. Clockwise";
		
		int t = sc.nextInt();
		int c = 1;
		
		char rubik[][] = new char[3][3];
		char board[][] = new char[3][3];
		
//		long start = System.currentTimeMillis();
		while(c<=t){
			for (int i = 0; i < rubik.length; i++){ 
				rubik[i] = sc.next().toCharArray();
				board[i] = rubik[i];
//				System.out.println(new String(board[i]));
			}
			int moves = BFS_Rubik2D(board);
			System.out.println("Case#"+(c++)+": "+moves+" move(s).");
		}
//		long end = System.currentTimeMillis();
//		System.out.println("time = "+(end-start));
	}
	
	static int BFS_Rubik2D(char board[][]){
		String readBoard = new String(board[0])+ "\n" +new String(board[1])+ "\n" +new String(board[2]);
		if(readBoard.equals(correctRubik))
			return 0;
		
		PriorityQueue<Board> pqueue = new PriorityQueue<Board>(new Comparator<Board>() {
			public int compare(Board b1, Board b2) {
				int zero1 = (b1.move==1 ? 5000:0);
				int zero2 = (b2.move==1 ? 5000:0);
				return (int)(((b2.point*100)-(b2.move*600)+zero2) - ((b1.point*100)-(b1.move*600)+zero1)); 
			}
		});
		ArrayList<String> visit = new ArrayList<String>();
		int move = 0;
		String path = "";
		float point = calcPoint(readBoard.replace("\n", ""));
		visit.add(readBoard);
		pqueue.add(new Board(board, move, path, point));
	
		char bb[][][] = new char[13][3][3];
		String newBoard[] = new String[13];
		float points[] = new float[13];
		int count = 0;
		
		while(!pqueue.isEmpty()){
			Board u = pqueue.poll();
			char b[][] = u.board;
			move = u.move;
			path = u.path;
			point = u.point;
			readBoard = new String(b[0])+ "\n" +new String(b[1])+ "\n" +new String(b[2]);
			
			for (int i = 0; i < b.length; i++) 
				for (int j = 1; j < bb.length; j++) 
					bb[j][i] = new String(b[i]).toCharArray();
			
			//Move 12 Patterns
			//1. Top Left
			bb[1][0] = ("" + bb[1][0][1] + bb[1][0][2] + bb[1][0][0]).toCharArray();
			newBoard[1] = new String(bb[1][0])+ "\n" +new String(bb[1][1])+ "\n" +new String(bb[1][2]);
			points[1] = calcPoint(newBoard[1].replace("\n", ""))+(float)0.01;
			
			//2. Top Right
			bb[2][0] = ("" + bb[2][0][2] + bb[2][0][0] + bb[2][0][1]).toCharArray();
			newBoard[2] = new String(bb[2][0])+ "\n" +new String(bb[2][1])+ "\n" +new String(bb[2][2]);
			points[2] = calcPoint(newBoard[2].replace("\n", ""))+(float)0.02;
			
			//3. Bottom Left
			bb[3][2] = ("" + bb[3][2][1] + bb[3][2][2] + bb[3][2][0]).toCharArray();
			newBoard[3] = new String(bb[3][0])+ "\n" +new String(bb[3][1])+ "\n" +new String(bb[3][2]);
			points[3] = calcPoint(newBoard[3].replace("\n", ""))+(float)0.03;
			
			//4. Bottom Right
			bb[4][2] = ("" + bb[4][2][2] + bb[4][2][0] + bb[4][2][1]).toCharArray();
			newBoard[4] = new String(bb[4][0])+ "\n" +new String(bb[4][1])+ "\n" +new String(bb[4][2]);
			points[4] = calcPoint(newBoard[4].replace("\n", ""))+(float)0.04;
			
			//5. Middle Swap Hori
			bb[5][1] = ("" + bb[5][1][2] + bb[5][1][1] + bb[5][1][0]).toCharArray();
			newBoard[5] = new String(bb[5][0])+ "\n" +new String(bb[5][1])+ "\n" +new String(bb[5][2]);
			points[5] = calcPoint(newBoard[5].replace("\n", ""))+(float)0.05;
			
			//6. Middle Swap Verti
			bb[6][0][1] = b[2][1];
			bb[6][2][1] = b[0][1];
			newBoard[6] = new String(bb[6][0])+ "\n" +new String(bb[6][1])+ "\n" +new String(bb[6][2]);
			points[6] = calcPoint(newBoard[6].replace("\n", ""))+(float)0.06;
			
			//7. Left Up
			for (int i = 0; i < b.length; i++) 
				bb[7][i][0] = b[(i+1)%3][0];
			newBoard[7] = new String(bb[7][0])+ "\n" +new String(bb[7][1])+ "\n" +new String(bb[7][2]);
			points[7] = calcPoint(newBoard[7].replace("\n", ""))+(float)0.07;
					
			//8. Left Down
			for (int i = 0; i < b.length; i++) 
				bb[8][i][0] = b[(i+2)%3][0];
			newBoard[8] = new String(bb[8][0])+ "\n" +new String(bb[8][1])+ "\n" +new String(bb[8][2]);
			points[8] = calcPoint(newBoard[8].replace("\n", ""))+(float)0.08;
			
			//9. Right Up
			for (int i = 0; i < b.length; i++) 
				bb[9][i][2] = b[(i+1)%3][2];
			newBoard[9] = new String(bb[9][0])+ "\n" +new String(bb[9][1])+ "\n" +new String(bb[9][2]);
			points[9] = calcPoint(newBoard[9].replace("\n", ""))+(float)0.09;
			
			//10. Right Down
			for (int i = 0; i < b.length; i++) 
				bb[10][i][2] = b[(i+2)%3][2];
			newBoard[10] = new String(bb[10][0])+ "\n" +new String(bb[10][1])+ "\n" +new String(bb[10][2]);
			points[10] = calcPoint(newBoard[10].replace("\n", ""))+(float)0.10;

			//11. Counter-Clockwise
			for (int i = 0; i < b.length; i++) 
				bb[11][i] = (""+b[0][2-i]+b[1][2-i]+b[2][2-i]).toCharArray();
			newBoard[11] = new String(bb[11][0])+ "\n" +new String(bb[11][1])+ "\n" +new String(bb[11][2]);
			points[11] = calcPoint(newBoard[11].replace("\n", ""))+(float)0.11;
			
			//12. Clockwise
			for (int i = 0; i < b.length; i++) 
				bb[12][i] = (""+b[2][i]+b[1][i]+b[0][i]).toCharArray();
			newBoard[12] = new String(bb[12][0])+ "\n" +new String(bb[12][1])+ "\n" +new String(bb[12][2]);
			points[12] = calcPoint(newBoard[12].replace("\n", ""))+(float)0.12;

			boolean isCorrect = false;
			for (int i = 1; i < newBoard.length; i++) {
				if(newBoard[i].equals(correctRubik)){
					move++;
					path += " "+i+" "+points[i];
					point = points[i];
					isCorrect = true;
					break;
				}
			}
			if(isCorrect)
				break;
			
			for (int i = 1; i < bb.length; i++) {
				if(!visit.contains(newBoard[i])){
					visit.add(newBoard[i]);
					pqueue.add(new Board(bb[i], move+1, path+" "+i+" "+points[i], points[i]));
				}
			}
			
			count++;
		}
//		System.out.println("run = "+count+" rounds.");
//		System.out.println("path = "+path);
//		System.out.println("Solution is");
//		String step[] = path.trim().split(" ");
//		for (int i = 0; i < step.length/2; i++) 
//			System.out.println("Step "+(i+1)+": "+pathName[Integer.parseInt(step[i*2])]+" ("+step[i*2+1]+")");
		
		return move;
	}
	
	//Total Point
	static float calcPoint(String read){
		float point = 0;
		String hori[] = new String[3];
		String verti[] = new String[3];
		for (int i = 0; i < hori.length; i++) {
			hori[i] = read.substring(i*3, i*3+3);
			verti[i] = ""+read.charAt(i)+read.charAt(3+i)+read.charAt(6+i);
			
			point += countScore(hori[i], correctHori[i]);
			point += countScore(verti[i], correctVerti[i]);
		}
		
		float sumNLT = 0;
		float sumNRT = 0;
		float sumNLB = 0;
		float sumNRB = 0;
		float sumNUL = 0;
		float sumNDL = 0;
		float sumNUR = 0;
		float sumNDR = 0;
		
		//Check NL NR NU ND
		for (int i = 0; i < hori.length; i++) {
			float nlt = (correctVerti[i].indexOf(hori[0].charAt((i+1)%3))==-1? 0: 0.25f);
			nlt += (correctVerti[i].charAt(0)==(hori[0].charAt((i+1)%3))? 1.0f: 0);
			sumNLT += nlt;
			
			float nrt = (correctVerti[i].indexOf(hori[0].charAt((i+2)%3))==-1? 0: 0.25f);
			nrt += (correctVerti[i].charAt(0)==(hori[0].charAt((i+2)%3))? 1.0f: 0);
			sumNRT += nrt;
			
			float nlb = (correctVerti[i].indexOf(hori[2].charAt((i+1)%3))==-1? 0: 0.25f);
			nlb += (correctVerti[i].charAt(2)==(hori[2].charAt((i+1)%3))? 1.0f: 0);
			sumNLB += nlb;
			
			float nrb = (correctVerti[i].indexOf(hori[2].charAt((i+2)%3))==-1? 0: 0.25f);
			nrb += (correctVerti[i].charAt(2)==(hori[2].charAt((i+2)%3))? 1.0f: 0);
			sumNRB += nrb;

			
			float nul = (correctHori[i].indexOf(verti[0].charAt((i+1)%3))==-1? 0: 0.25f); 
			nul += (correctHori[i].charAt(0)==(verti[0].charAt((i+1)%3))? 1.0f: 0);
			sumNUL += nul;
			
			float ndl = (correctHori[i].indexOf(verti[0].charAt((i+2)%3))==-1? 0: 0.25f); 
			ndl += (correctHori[i].charAt(0)==(verti[0].charAt((i+2)%3))? 1.0f: 0);
			sumNDL += ndl;
			
			float nur = (correctHori[i].indexOf(verti[2].charAt((i+1)%3))==-1? 0: 0.25f); 
			nur += (correctHori[i].charAt(2)==(verti[2].charAt((i+1)%3))? 1.0f: 0);
			sumNUR += nur;
			
			float ndr = (correctHori[i].indexOf(verti[2].charAt((i+2)%3))==-1? 0: 0.25f); 
			ndr += (correctHori[i].charAt(2)==(verti[2].charAt((i+2)%3))? 1.0f: 0);
			sumNDR += ndr;
			
//			System.out.println("nlt\tnrt\tnlb\tnrb\tnul\tndl\tnur\tndr");
//			System.out.println(nlt+"\t"+nrt+"\t"+nlb+"\t"+nrb+"\t"+nul+"\t"+ndl+"\t"+nur+"\t"+ndr);
			
			point += nlt+nrt+nlb+nrb+nul+ndl+nur+ndr;
		}
		
		point += scoreCombo(sumNLT);
		point += scoreCombo(sumNRT);
		point += scoreCombo(sumNLB);
		point += scoreCombo(sumNRB);
		point += scoreCombo(sumNUL);
		point += scoreCombo(sumNDL);
		point += scoreCombo(sumNUR);
		point += scoreCombo(sumNDR);
		
		return point;
	}
	
	//Addition Combo Score
	static float scoreCombo(float sum){
		if(sum>3.0f)
			return 1.5f;
		if(sum>2.0f)
			return 0.5f;
		return 0.0f;
	}

	//Count Score
	static float countScore(String text, String org){
		float count = 0;
		for (int i = 0; i < org.length(); i++) {
			int pos = text.indexOf(org.charAt(i));
			if(pos!=-1)
				count+=2;
			if(pos==i)
				count+=1;
		}
		
		return count;
	}
	
	//Inner Class
	static class Board{
		char board[][] = new char[3][3];
		int move = 0;
		String path = "";
		float point = 0.0f;
		
		public Board(char board[][], int move, String path, float point){
			for (int i = 0; i < board.length; i++) 
				this.board[i] = board[i];
			this.move = move;
			this.path = path;
			this.point = point;
		}
	}
}
