import java.util.*;
import java.time.*;
import java.text.*;
public class ageCalculator
{ 
    public static void main(String[] args)
    {
        
        Calendar calendar = Calendar.getInstance();
        int date = calendar.get(Calendar.DATE);
        int month = calendar.get(Calendar.MONTH);
        int year = calendar.get(Calendar.YEAR);

        System.out.println("Current Calendar's Year: " + year );
        System.out.println("Current Calendar's Day: " + date  );
        System.out.println("Current Calendar's Month: " + month);

        Scanner DOB =new Scanner(System.in);
        System.out.println("Enter Birth Year");
        int birthYear = DOB.nextInt();
        System.out.println("Enter Birth Month in integer eg. 03");
        int birthMonth = DOB.nextInt();
        System.out.println("Enter Birth Date");
        int birthDate = DOB.nextInt();

        

        LocalDate start_date = LocalDate.of(birthYear,birthMonth,birthDate);
  
        // End date
        LocalDate end_date = LocalDate.of(year,month,date);

        Period diff = Period.between(start_date,end_date);


        System.out.print("You are : ");

        // Print the result
        System.out.printf("%d years, %d months"+ " and %d days "+"old",diff.getYears(),diff.getMonths(),diff.getDays());
        


    }
}