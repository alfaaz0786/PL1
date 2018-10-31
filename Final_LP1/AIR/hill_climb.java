
import java.io.*;
import java.lang.Math;

//Class for Hill Climbing
class Hill_Climbing
{
	//int []place = {0,1,2,3,2,1,1,2,3,4,5,4,3,2,1,0,0,0};
	int []place = {0,1,2,3,4,5,6,7,8,9,8,7,6,5,3,3,3,3,0};
	int start = 15;
	int goal = 9;
					

	void startClimb() throws Exception
	{
		int current = start;
		int count = 0;

		System.out.print("\n\nThe structure of Hill is ");
		for (int i=0; i<place.length; i++)
		{
			System.out.print(" " + place[i]);
		}

		System.out.print("\n\nWe are starting from position=" + current + " value=" + place[current]);
		System.out.print("\nWe want to go to position=" + goal + " value=" + place[goal] + "\n\n");

		int move; 										//-1 for left, 0 to stay, 1 for right
		int left_h, curr_h, right_h;
		while(current!=goal)
		{
			if(current==0)
				move = 1;
			else if (current == place.length-1)
				move = -1;
			else
			{
				left_h = getHeuristic(current-1);
				right_h = getHeuristic(current+1);
				curr_h = getHeuristic(current);

				if(right_h<curr_h && right_h<left_h)
				{
					move = 1;
				}
				else if (left_h<curr_h && left_h<right_h)
				{
					move = -1;
				}
				else
				{
					move = 0;
				}
			}	
			count++;
			
			System.out.print("Movement="+move);
			current = current + move;
			System.out.println("\tNew position="+current+" value="+place[current]);

			Thread.sleep(800);
		}
		System.out.print("\n\nWe have reached the goal position in "+count+" steps.");
	}

	int getHeuristic(int pos)
	{
		return place[goal] - place[pos];
	}
}

//Main Function
public class hill_climb
{
	public static void main(String args[]) throws Exception
	{
		Hill_Climbing obj = new Hill_Climbing();
		obj.startClimb();
	}
}