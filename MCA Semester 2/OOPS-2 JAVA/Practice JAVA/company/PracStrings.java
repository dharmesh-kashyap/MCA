package com.company;

public class PracStrings {
    public static void main(String[] args) {
         String name = new String("  Dharmesh  ");
         String newm = "    Kashyap   ";
         String x = name.toUpperCase();
        System.out.println(name);
        System.out.println(newm.trim());
        System.out.println(name.substring(3,5));
        System.out.println(name.replace(" ","_"));
        System.out.println(name.startsWith("h"));
        System.out.println(name.endsWith("es"));
        System.out.println(name.charAt(5));
        System.out.println(name.lastIndexOf("Dh"));
        System.out.println(name.equals("Dhamesh"));
        System.out.println(x);
        System.out.println("Remastered Version of god");

    }
}
