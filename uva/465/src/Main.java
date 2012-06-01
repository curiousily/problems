import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static int N;

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(terminalReader());
		BigInteger max = new BigInteger(String.valueOf(Integer.MAX_VALUE));
		while (scanner.hasNext()) {
			String line = scanner.nextLine();
			boolean isPlus = line.contains("+");
			String operator = isPlus ? "\\+" : "\\*";
			String[] parts = line.split(operator);
			BigInteger first = new BigInteger(parts[0].trim());
			BigInteger second = new BigInteger(parts[1].trim());
			BigInteger result = isPlus ? first.add(second) : first
					.multiply(second);
			System.out.println(line);
			if (first.compareTo(max) > 0) {
				System.out.println("first number too big");
			}
			if (second.compareTo(max) > 0) {
				System.out.println("second number too big");
			}
			if (result.compareTo(max) > 0) {
				System.out.println("result too big");

			}
		}
	}

	private static BufferedReader fileReader() throws FileNotFoundException {
		return new BufferedReader(new FileReader(new File("in.txt")));
	}

	private static BufferedReader terminalReader() {
		return new BufferedReader(new InputStreamReader(System.in));
	}
}