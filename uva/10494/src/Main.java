import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(terminalReader());
		while (scanner.hasNext()) {
			String line = scanner.nextLine();
			boolean isDivide = line.contains("/") ? true : false;
			String[] numbers = line.split("\\/|\\%");
			BigInteger first = new BigInteger(numbers[0].trim());
			BigInteger second = new BigInteger(numbers[1].trim());
			if (isDivide) {
				System.out.println(first.divide(second).toString());
			} else {
				System.out.println(first.mod(second).toString());
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