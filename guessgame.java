public class guessgame {
	public static void main(String[] args) {
		gamelogic game = new gamelogic();
		game.start();
	}
}

class player {
	int gue = 0;
	public void guess() {
		gue = (int)(Math.random()*10);
		System.out.println("guesses " + gue);
	}
}

class gamelogic {
	player p1;
	player p2;
	player p3;
	
	public void start() {
		int toguess = (int)(Math.random() * 10);
		System.out.println("Number to be guessed = " + toguess);
		
		p1 = new player();
		p2 = new player();
		p3 = new player();
		
		while (true) {
		
			System.out.print("player 1 ");
			p1.guess();
			System.out.print("player 2 ");
			p2.guess();
			System.out.print("player 3 ");
			p3.guess();
		
			boolean p1right = false;
			boolean p2right = false;
			boolean p3right = false;
		
			if (p1.gue == toguess)
				p1right = true;
			if (p2.gue == toguess)
				p2right = true;
			if (p3.gue == toguess)
				p3right = true;
		
			if (p1right) {
				System.out.println("player 1 is right");
			}
			if (p2right) {
				System.out.println("player 2 is right");
			}
			if (p3right) {
				System.out.println("player 3 is right");
			}
			if (p1right || p2right || p3right)
				break;
			
			System.out.println("");
		}
	}
}