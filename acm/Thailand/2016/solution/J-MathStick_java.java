import java.util.Scanner;

//Coding by Mr.Prapot Thumsiraruk
public class J_MathStick_OK {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		while(t-->0){
			String s = sc.next();
			if(isPalindromeUpSideDown(s))
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}
	
	static boolean isPalindromeUpSideDown(String s){
		if(s.contains("3") || s.contains("4")  || s.contains("7"))
			return false;
		
		if(s.length()==1){
			if(s.equals("6") || s.equals("9"))
				return false;
			return true;
		}
		
		if((s.contains("6") && !s.contains("9")) || (s.contains("9") && !s.contains("6")))
			return false;
		if(s.contains("6") && s.contains("9")){
			int six = countSameString(s, "6");
			int nine = countSameString(s, "9");
			if(six!=nine)
				return false;
			s = s.replace("6", "A").replace("9", "A");
		}
		
		StringBuffer sb = new StringBuffer(s);
		String rev = sb.reverse()+"";
		if(!s.equals(rev))
			return false;
		return true;		
	}

	static int countSameString(String data , String str){
		int pos = 0;
		int count = 0;
		while(true){
			pos = data.indexOf(str,pos);
			if(pos==-1)   break;
			pos++; count++;
		}
		return count;
	}  	
	
}
