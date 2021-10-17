class fibonocci{

	static int f(int x)
	{
		if (x <= 1)
			return x;
		
		return f(x-1) + f(x-2);
		
	}
	
	public static void main(String[] args){
		int n=10;

		for (int i = 0; i < n; i++) {
			System.out.printf("%d  ", f(i));
		}
	}
}
