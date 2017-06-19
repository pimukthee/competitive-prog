import java.util.Scanner;

//Coding by Mr.Prapot Thumsiraruk
public class E_ElevatorGOplus_OK {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int c = 1;
		while(true){
			int high = sc.nextInt();
			if(high==0)
				break;
			
			int order = sc.nextInt();
			int old_floor = 0;
			int new_floor = 0;
			int old_room = 0;
			int new_room = 0;
			int totalTime = 0;
			
			for (int i = 0; i < order; i++) {
				String go = sc.next();
				int len = go.length();
				new_floor = Integer.parseInt(go.substring(0, len-2),8);
				new_room = Integer.parseInt(go.substring(len-2, len),8);
				
				//Move to center before
				if(old_room!=0 && (old_floor!=new_floor)){
					int toCenter = timeLeftRight(old_room, 0, high);
					totalTime += toCenter;
					old_room = 0;
				}
				
				int timeUD = timeUpDown(old_floor, new_floor);
				int timeLR = timeLeftRight(old_room, new_room, high);
				totalTime += timeUD+timeLR;
				
				old_floor = new_floor;
				old_room = new_room;
			}
			System.out.println("#"+(c++)+": "+hms(totalTime));
		}
	}
	
	static int timeUpDown(int old_floor, int new_floor){
		if(old_floor==new_floor)
			return 0;
		
		if(new_floor>old_floor)
			return 6*(new_floor-old_floor)+5;
		return 4*(old_floor-new_floor)+5;
	}
	
	static int timeLeftRight(int old_room, int new_room, int high){
		if(old_room==new_room)
			return 0;
		
		int half = high/2;
		int dif = 0;
		if((old_room>0 && old_room<=half && new_room>half) || (old_room>half && new_room>0 && new_room<=half))
			dif++;
		
		if(old_room==0 && new_room>half)
			old_room = half;
		else if(old_room==0 && new_room<=half)
			old_room = half+1;
		else if(old_room>half && new_room==0)
			new_room = half;
		else if(old_room<=half && new_room==0)
			new_room = half+1;
		
		dif += Math.abs(new_room-old_room);
		
		return 3*dif+5;
	}
	
	static String hms(int sec){
		String time = "";

		if(sec>=3600){
			time += (sec/3600)+"h ";
			sec %= 3600;
		}
		if(sec>=60){
			time += (sec/60)+"m ";
			sec %= 60;
		}
		if(sec>0)
			time += sec+"s";
		
		return time.trim();
	}

}
