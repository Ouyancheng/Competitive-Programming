import java.util.*;
import java.text.*;

public class B {
	static String[] s1 = null, s2 = null;
	static int[] ss2 = new int[3];
	static Vector<Date> dates = new Vector<>();
	static final String fs = "dd/MM/yyyy";
	static SimpleDateFormat format = new SimpleDateFormat(fs);

	public static int age(Date birthday, Date date) {
	    DateFormat formatter = new SimpleDateFormat("yyyyMMdd");
	    int d1 = Integer.parseInt(formatter.format(birthday));
	    int d2 = Integer.parseInt(formatter.format(date));
	    int age = (d2-d1)/10000;
	    return age;
	}

	public static boolean val(String x,String y,String z) {
		try {
            format.parse(x + "/" + y + "/" + "20" + z);
        } catch (ParseException e) {
            return false;
        } catch (IllegalArgumentException e) {
            return false;
        }
        return true;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		s1 = in.next().split("\\.");
		s2 = in.next().split("\\.");
		format.setLenient(false);
		for(int i = 0; i < s2.length; i++) ss2[i] = Integer.parseInt(s2[i]); 
		Date d1 = format.parse(s1[0] + "/" + s1[1] + "/20" + s1[2]);

		if(val(s2[0],s2[1],s2[2])) dates.add(format.parse(s2[0] + "/" + s2[1] + "/20" + s2[2]));
		//System.out.println(dates);
		if(val(s2[0],s2[2],s2[1])) dates.add(format.parse(s2[0] + "/" + s2[2] + "/20" + s2[1]));
		//System.out.println(dates);
		if(val(s2[1],s2[0],s2[2])) dates.add(format.parse(s2[1] + "/" + s2[0] + "/20" + s2[2]));
		//System.out.println(dates);
		if(val(s2[1],s2[2],s2[0])) dates.add(format.parse(s2[1] + "/" + s2[2] + "/20" + s2[0]));
		//System.out.println(dates);
		if(val(s2[2],s2[0],s2[1])) dates.add(format.parse(s2[2] + "/" + s2[0] + "/20" + s2[1]));
		//System.out.println(dates);
		if(val(s2[2],s2[1],s2[0])) dates.add(format.parse(s2[2] + "/" + s2[1] + "/20" + s2[0]));
		//System.out.println(dates);
		for(int i = 0; i < dates.size(); i++) {
			Date d = dates.get(i);
			long mdiff = d1.getTime() - d.getTime();
			if(mdiff > 0) {
				if(age(d,d1)>=18) {
					System.out.println("YES");
					return;
				}
			}
		}
		System.out.println("NO");
	}
}