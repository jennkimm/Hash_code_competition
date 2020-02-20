import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

public class hashcode_long {

	public static void main(String[] args) throws IOException {
		String fileName="f_libraries_of_the_world.txt";
		BufferedReader br = null;
		
		// read file
		try {
			br = new BufferedReader(new FileReader(fileName));
		}catch(FileNotFoundException e) {
			System.out.println("Error in opening a file.\n");
			System.exit(0);
		}
		
		// first line
		String[] first=br.readLine().split(" ");
		int librariesNum = Integer.parseInt(first[1]);
		long days = Long.parseLong(first[2]);

		// second line
		String[] second = br.readLine().split(" ");
		long[] scores = new long[second.length];
		for (int i=0;i<second.length;i++) {
			scores[i] = Long.parseLong(second[i]);
		}
		
		Library_long[] libraries = new Library_long[librariesNum];
		for (int i=0;i<librariesNum;i++) {
			String[] info = br.readLine().split(" ");
			libraries[i] = new Library_long(
					Integer.parseInt(info[0]),Integer.parseInt(info[1]),Integer.parseInt(info[2]));
			String[] booksInLibrary = br.readLine().split(" ");
			for (int j=0;j<booksInLibrary.length;j++) {
				long book = Long.parseLong(booksInLibrary[j]);
				libraries[i].books[j]=book;
			}
		}
		
		long rest = days;
		
		long count = 0;
		for (int i=0;i<libraries.length;i++) {
			rest -= libraries[i].sign;
			if(rest<0) break; // deadline 안에 signup 실패
			count++;
		}
		
		fileName="f_result.txt";
		PrintWriter outStream=null;
		try {
			outStream=new PrintWriter(fileName);
		}catch(FileNotFoundException e) {
			System.out.println("Exception Occurs");
			System.exit(0);
		}
		rest = days;
		outStream.println(count);
		for (int i=0;i<libraries.length;i++) {
			rest -= libraries[i].sign;
			if(rest<0) break; // deadline 안에 signup 실패
			long maxBook = rest*libraries[i].ship;
			long scannedBook;
			if(maxBook<=libraries[i].booksNum) scannedBook = maxBook;
			else scannedBook = libraries[i].booksNum;
			outStream.println(i+" "+scannedBook);
			
			for (int j=0;j<scannedBook;j++) {
				outStream.print(libraries[i].books[j]+" ");
			}
			outStream.println();
		}
		outStream.close();
	}

}

class Library_long {
	
	int booksNum;
	long sign, ship;
	long[] books;
	
	Library_long(){}
	Library_long(int booksNum, long sign, long ship){
		this.booksNum = booksNum;
		this.sign = sign;
		this.ship = ship;
		books = new long[booksNum];
	}
	
}


