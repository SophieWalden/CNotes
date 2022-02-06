![1](https://user-images.githubusercontent.com/37228858/152700036-d7cf16fb-0dfd-4d65-bf20-7a35de22dc1e.png)

Write snippets of C code in your txt files for notes and skip the hassle of compiling and running.
Greatly helps organization and note-taking to make sure you do not miss anything.

Simply just run either the CNotes (Linux) or CNotes.exe (Windows) and specify file name as an argument and it will look through and create the program for you.

Works with functions, structs, and whatnot more

Example:

~{

int sum_func(int x, int y){
	return x + y;
}

int x = 5;
int y = 26;
int total = sum_func(x, y);

printf("%d", total);

}~

Everything will be sorted and put into the main function as needed, so no need to define it yourself
See Example.txt for more examples

Support for #include and more custom stuff soon!

Built it because I would have a tab open and 2 terminals and be switching around trying to compile and take notes at the same time, it just was not possible to keep up with the professor. This should be a bit of a help, hoping to expand on it in the future

Join the Diviware community and hear more about updates on this software and upcoming projects here:
https://discord.gg/QcY7NznN3A
