#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getInputFileName(int argc, char** argv){
	bool file_name_found = false;
	char* input_file_name;
	
	if (argc >= 2){
		for (int i = 0; i < argc; i++){
			if (strcmp(argv[i], "--file_name")){
				input_file_name = argv[i];
				file_name_found = true;
			}
		}
	}

	if (!file_name_found){
		printf("Please supply a file name using --file_name [file_name]\n");
		exit(1);
	}
	
	return input_file_name;


}

int parseProgram(char* input_file_name){

	FILE *input_file;
 	FILE *output_file;
 	FILE *checking_for_end_of_file;
	bool in_program = false;
	bool program_made = false;
	int program_count = 0;
	char current_line[100];
	
	input_file = fopen(input_file_name, "r");

	while (fgets(current_line, sizeof(current_line), input_file)) { 		
		
		if (current_line[0] == '~' && current_line[1] == '{'){ // Snippet Found
			in_program = true;
			program_made = true;
			program_count++;
		
			char output_file_name[100];
			snprintf(output_file_name, 100, "output%d.c", program_count);
			output_file = fopen(output_file_name, "wb");

			fprintf(output_file, "#include <stdio.h>\n\nint main(){\n"); 
		}
		
		else if (in_program){
			if (current_line[0] == '}' && current_line[1] == '~'){ // Snippet Ended
				fprintf(output_file, "}");
				fclose(output_file);
				in_program = false;
			}else{
				
				fprintf(output_file, "%s", current_line);
				
			}
		}
	
	} 
	
	fclose(input_file);
	if (in_program){
		fclose(output_file);
	}
	
	return program_count;
}

void run_programs(int program_count){
	for (int i = 1; i < program_count+1; i++){
		printf("\n\nSnippet %d:\n", i);
			
			
		char command[100];
		snprintf(command, 100, "gcc output%d.c -o NotesProgram.exe", i);
			
		system(command);
		system("NotesProgram.exe");
				
	}
}

int main(int argc, char** argv){
 
	int program_count;
	char* input_file_name;
	
	input_file_name = getInputFileName(argc, argv);
	
	program_count = parseProgram(input_file_name);
	
	if (program_count != 0){ 
		run_programs(program_count);
	}
		
	return 0;
}
