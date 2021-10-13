package  dbb;

  import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class Dbb {
    public static void main(String[] args) {
Connection conn;

try {
    conn =DriverManager.getConnection("jdbc:mysql://sql6.freesqldatabase.com:3306/sql6443610","sql6443610","KIY7b1wHTw");  
    System.out.println("Success");
   
} catch (SQLException ex) {
    System.out.println("SQLException: " + ex.getMessage());
    System.out.println("SQLState: " + ex.getSQLState());
    System.out.println("VendorError: " + ex.getErrorCode());
}

    }
}