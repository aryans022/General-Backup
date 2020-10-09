class Olution {
    public static String solution(String str) {
    	String toReturn = "";
		
		String[] codes = {"100000", "110000", "100100", "100110", "100010", "110100", "110110", "110010",
						  "010100", "010110", "101000", "111000", "101100", "101110", "101010", "111100",
						  "111110", "111010", "011100", "011110", "101001", "111001", "010111", "101101",
						  "101111", "101011", "000001", "000011", "000000"};
		
		char[] converted = str.toCharArray();
		int index;
		
		for(char current : converted) {
			
			if (Character.isUpperCase(current)) {
				
				toReturn += codes[26];
				current = Character.toLowerCase(current);
				
			}
				
			index = current - 97;
			if (index == -65) {
				toReturn += codes[28];
			}
			else {
				toReturn += codes[index];
			}
			
		}
		
		return toReturn;
    }
}

public class Solution {
	public static void main(String[] args) {
		System.out.println(Olution.solution("code"));
	}
}