import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class NumberRecognition{

	public String[] T = new String[10];
	static int numcase=0;
	public int W,H=0;
	public static int data[][]=null;
	int temP=-1;
	int checkline=0;
	int hi=0;
	static List<Integer> answer = new LinkedList<Integer>();
	public void template()
	{
		T[0] ="111101101101101101111";//0
	    T[1] ="1111111"; //1
	    T[2] ="111001001111100100111"; //2
	    T[3] ="111001001111001001111";
	    T[4] ="101101101111001001001";
	    T[5] ="111100100111001001111";
	    T[6] ="111100100111101101111";
	    T[7] ="111001001001001001001";
	    T[8] ="111101101010101101111";
	    T[9] ="111101101111001001111";//9
	    

	}
	public void readInput(){
		
		try{
		 BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
         String sCurrentLine = stdin.readLine();
         	numcase= Integer.parseInt(sCurrentLine.trim());	
         	for(int num=1;num<=numcase;num++){
         		sCurrentLine = stdin.readLine();
         		String [] numWH=sCurrentLine.split(",");
         		H=Integer.parseInt(numWH[0]);
				W=Integer.parseInt(numWH[1]);
				data=new int[H][W];					
				
					for(int row=0;row<H;row++){	
						sCurrentLine = stdin.readLine();
						String[]getdata=sCurrentLine.split(",");
						for(int col=0;col<getdata.length;col++){
							data[row][col]=Integer.parseInt(getdata[col]);
						}
						
					}						
					
				showAnswer();
				
         		
         	}// end for
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	
		
	}
	public void showAnswer(){
		answer.clear();							
		int w=6,h=14;								
		slidWindow(h,w,2);
		h=7;w=3;
		slidWindow(h,w,1);
		//sort
				Collections.sort(answer);				
							
				List<Integer> unique = removeDuplicates((answer));
				int check=0;
				for (Integer element : unique) {
					if(check<unique.size()-1){
						System.out.print(element+",");
					}else System.out.print(element);
					check++;
				}				
				//count
				int[] number=new int[answer.size()];
				for(int j=0;j<answer.size();j++){
					number[j]=answer.get(j);
				}
		       	Map map= new HashMap();
		        for(Integer s: number){
		        	map.put(s,Collections.frequency(answer,s));
		        }
		        System.out.println();
		       
		        String countnum="";
		        for(int j=0;j<10;j++){
		        	if(map.get(j)!=null){
		        		countnum=countnum+map.get(j)+",";
		        	}		        	
		        }
		      
		        for(int j=0;j<countnum.length()-1;j++){
		        	System.out.print(countnum.charAt(j));
		       }
		        if(checkline!=numcase) 	System.out.println();		        
	}
	public void slidWindow(int h,int w,int s){
		
		int [][]dataWin=new int[h][w];
		int[][] dataresize=new int[h][w];
		int row=0;
		int col=0;		
		try{
			while(row<H){
				while(col<W){					
					for(int r=0;r<h;r++){
						for(int c=0;c<w;c++){
							if(((col+c)==(W))){
								  row=row+1;
									col=0;									
							}else if((row+r)==H){
								row=H;								
							}else if((col+c!=W)&&(col<(W-(w-1)))){								
								dataWin[r][c]=data[row+r][col+c];
							}
							
						}//for c
					}//for r
					
					//process double size
					if(s==2){
						dataresize=resize(dataWin);
						String newdata=arraytoString(dataresize);
						int temP=recognition(newdata);	
						if(temP!=-1){
							answer.add(temP);
							//reset to zeros
							for(int r=0;r<h;r++){
								for(int c=0;c<w;c++){
									data[row+r][col+c]=0;
								}
							}
						}
					}// end process double size
					
					//process normal size
					if(s==1){
						String newdata=arraytoString(dataWin);
						int temP=recognition(newdata);
						if(temP!=-1){
							answer.add(temP);
							//reset to zeros
							for(int r=0;r<h;r++){
								for(int c=0;c<w;c++){
									data[row+r][col+c]=0;
								}
							}
						}						
					}					
					col++;		
				}// while col
			}//while row
		}catch(ArrayIndexOutOfBoundsException exception) {
		    
		}
		if(s==2){
		//check Double one Number
			checkOneNumber(2);		
		}
		if(s==1){
			checkOneNumber(1);
		}
	}//end method  
	//Resize
	public int[][] resize(int dataWin[][]){
		int start=0,center=3,stop=6;
		int h=7,w=3;
		int[][] doubledataWin=new int[h*2][w*2];
		int[][] dataResizeH=new int[h][w*2];
		int[][] dataresize=new int[h][w];
		doubledataWin=dataWin;
		// Rescale Hight
		for (int i=0;i<w*2;i++){
			dataResizeH[start][i]=doubledataWin[0][i];
			dataResizeH[center][i]=doubledataWin[7][i];
			dataResizeH[stop][i]=doubledataWin[13][i];
			
		}// for
		
			dataResizeH[start+1][0]=doubledataWin[start+1][0];						
			dataResizeH[start+2][0]=doubledataWin[start+1][0];
			dataResizeH[start+1][(w*2)-1]=doubledataWin[start+1][(w*2)-1];
			dataResizeH[start+2][(w*2)-1]=doubledataWin[start+1][(w*2)-1];
			dataResizeH[center+1][0]=doubledataWin[(center+1)*2][0];
			dataResizeH[center+2][0]=doubledataWin[(center+1)*2][0];
			dataResizeH[center+1][(w*2)-1]=doubledataWin[(center+1)*2][(w*2)-1];
			dataResizeH[center+2][(w*2)-1]=doubledataWin[(center+1)*2][(w*2)-1];
			//Rescale Width
			for(int i=0;i<h;i++){
				dataresize[i][0]=dataResizeH[i][0];
				dataresize[i][w-1]=dataResizeH[i][(w*2)-1];
			}//for
			dataresize[start][1]=dataResizeH[start][1];
			dataresize[center][1]=dataResizeH[center][1];
			dataresize[stop][1]=dataResizeH[stop][1];						
					
		return dataresize;
	
	}
	public String arraytoString(int[][]arraydata){
		int j=0;
		String newdata="";
		String flagstring="";
		for(int r=0;r<7;r++){
			for(int c=0;c<3;c++){
				flagstring=Integer.toString(arraydata[r][c]);
				newdata=newdata+flagstring;
				j++;
			}			
		}
		return newdata;
		
	}
	public int recognition(String newdata){
		int temP=-1;
		template();	
		
		for(int num=0;num<=9;num++){
			if(T[num].equals(newdata)){
				temP=num;
				
			}
		}
		return temP;
	}
	public int checkOneNumber(int s){
		String One="";
		int h=0,w=0;
		if(s==1){
			One="1111111";
			h=7;
			w=3;
		}else if(s==2){
			 One="11111111111111";
			 h=14;w=6;
		}
		 
		int temp=-1;
		int row=0;
		int col=0;
		// Check number One
		try{
				while(row<H){
					while(col<W){
												
							String checkone="";
						for(int num=0;num<h;num++){
								if(((col)==(W-1))){									
									row=row+1;
									col=0;
									
								}else if((row+num)==H){
									row=H;
								
								}else{
									checkone=checkone+Integer.toString(data[row+num][col]);	
								}
								
							}
						if(checkone.equals(One)){
								temp=1;
								answer.add(temp);
								//reset to zeros
								for(int num=0;num<h;num++){
									if(((col)==(W-1))){									
																				
									}else if((row+num)==H){
										
									
									}else{
										data[row+num][col]=0;	
									}
									
								}
							}
							
						col++;
							
					}//col
				}//while row
		}catch(ArrayIndexOutOfBoundsException exception) {
		    
		}
		return temp;
	}
	static List<Integer> removeDuplicates(List<Integer> l) {

			// Store unique items in result.
			List<Integer> result = new LinkedList<Integer>();
			// Record encountered Strings in HashSet.
			HashSet<Integer> set = new HashSet<>();
			// Loop over argument list.
			for (Integer item : l) {

			    // If String is not in set, add it to the list and the set.
			    if (!set.contains(item)) {
				result.add(item);
				set.add(item);
			    }
			}
			return result;
		}
	public static void main(String[] args) {
		final long startTime = System.currentTimeMillis();
		NumberRecognition obj=new NumberRecognition();
		obj.readInput();			
		final long endTime = System.currentTimeMillis();
		System.out.println("Total execution time: " + (endTime - startTime) );
	}

}
