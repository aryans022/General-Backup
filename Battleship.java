import java.util.ArrayList;
import java.io.*;
import java.util.*;

public class Battleship {
	
	private int numGuess = 0;
	private GameHelper helper = new GameHelper();
	private ArrayList<Ship> shipList = new ArrayList<Ship>();
	
	private void gameSetup() {
		
		Ship ship1 = new Ship();
		ship1.setName("Ship 1");
		shipList.add(ship1);
		
		Ship ship2 = new Ship();
		ship2.setName("Ship 2");
		shipList.add(ship2);
		
		Ship ship3 = new Ship();
		ship3.setName("Ship 3");
		shipList.add(ship3);
		
		for (Ship shipx : shipList) {
			ArrayList<String> location = helper.placeDotCom(3);
			shipx.setLocation(location);
		}
	}
	
	private void gameStart() {
		
		while(!shipList.isEmpty()) {
			String userGuess = helper.getUserInput("Enter a guess.");
			checkUserGuess(userGuess);
		}
		gameFinish();
	}
	
	private void checkUserGuess(String userGuess) {
		
		numGuess++;
		String result = "miss";
		
		for (Ship shipx : shipList) {
			
			result = shipx.checkGuess(userGuess);
			
			if (result.equals("hit")) {
				break;
			}
			if (result.equals("kill")) {
				shipList.remove(shipx);
				break;
			}
		}
		System.out.println(result);
	}
	
	private void gameFinish() {
		System.out.println("All ships are dead! Your stock is now worthless.");
		if (numGuess <= 18) {
			System.out.println("It only took you " + numGuess + "guesses.");
		}
		else {
			System.out.println("Took you long enough...");
		}
	}
	
	public static void main(String[] args) {
		Battleship game1 = new Battleship();
		game1.gameSetup();
		game1.gameStart();
	}

}

class Ship {
	
	private String name;
	private ArrayList<String> loc;
	
	public void setLocation(ArrayList<String> locat) {
		loc = locat;
	}
	
	public void setName(String shipName) {
		name = shipName;
	}
	
	String checkGuess(String userInput) {
		
		String result = "miss";
		int index = loc.indexOf(userInput);
		
		if (index >= 0) {
			
			loc.remove(index);
		
			if (loc.isEmpty()) {
				result = "kill";
				System.out.println("Ouch ! You sunk " + name);
			}
			else {
				result = "hit";
			}
		}
		return result;
	}
}

class GameHelper {
	
	private static final String alphabet = "abcdefg";
	private int gridLength = 7;
	private int gridSize = 49;
	private int [] grid = new int[gridSize];
	private int comCount = 0;
	
	public String getUserInput(String prompt) {
		String inputLine = null;
		System.out.print(prompt + " ");
		try {
			BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
			inputLine = is.readLine();
			if (inputLine.length() == 0 )
				return null;
			}
			
		catch (IOException e) {
			System.out.println("IOException: " + e);
		}
		return inputLine.toLowerCase();
	}
	
	public ArrayList<String> placeDotCom(int comSize) {
		ArrayList<String> alphaCells = new ArrayList<String>();
		String [] alphacoords = new String [comSize]; 					// holds ‘f6’ type coords
		String temp = null; 											// temporary String for concat
		int [] coords = new int[comSize]; 								// current candidate coords
		int attempts = 0; 												// current attempts counter
		boolean success = false; 										// fl ag = found a good location ?
		int location = 0; 												// current starting location
		
		comCount++; 													// nth dot com to place
		int incr = 1; 													// set horizontal increment
		if ((comCount % 2) == 1) { 										// if odd dot com (place vertically)
			incr = gridLength; 											// set vertical increment
		}
		
		while ( !success & attempts++ < 200 ) { 						// main search loop (32)
			location = (int) (Math.random() * gridSize); 				// get random starting point
			int x = 0;													// nth position in dotcom to place
			success = true; 											// assume success
			
			while (success && x < comSize) { 							// look for adjacent unused spots
			
				if (grid[location] == 0) { 								// if not already used
					coords[x++] = location; 							// save location
					location += incr; 									// try ‘next’ adjacent
					if (location >= gridSize){ 							// out of bounds - ‘bottom’
						success = false; 								// failure
					}
					if (x>0 && (location % gridLength == 0)) { 			// out of bounds - right edge
						success = false; 								// failure
					}
				}
				else { 													// found already used location
					success = false; // failure
				}
			}
		} 																// end while
		
		int x = 0; 														// turn location into alpha coords
		int row = 0;
		int column = 0;
	
		while (x < comSize) {
			grid[coords[x]] = 1; 										// mark master grid pts. as ‘used’
			row = (int) (coords[x] / gridLength); 						// get row value
			column = coords[x] % gridLength; 							// get numeric column value
			temp = String.valueOf(alphabet.charAt(column)); 			// convert to alpha
			alphaCells.add(temp.concat(Integer.toString(row)));
			x++;
		}
		
		return alphaCells;
	}
}
