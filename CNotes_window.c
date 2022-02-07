#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// TODO:
// Put functions outside of main function
// argument for putting in text file or scan for text file in directory

int main(int argc, char* argv[]){
 
 	FILE *input_file;
 	FILE *output_file;
 	FILE *checking_for_end_of_file;
	bool in_program = false;
	bool program_made = false;
	int program_count = 0;
	char current_line[100];
	char check_for_end_of_file = ' ';
	char input_file_name[100];
	bool file_name_found = false;
		
	// Grab Input name
	if (argc >= 2){
		for (int i = 0; i < argc; i++){
		
			if (strcmp(argv[i], "--file_name")){
				sscanf(argv[i], "%s", input_file_name); 
				//strcpy(input_file_name, argv[i+1]);
				file_name_found = true;
			}
		}
	}

	if (!file_name_found){
		printf("Please supply a file name using --file_name [file_name]\n");
		return 1;
	}
	
	
	
	// Grab Program
	input_file = fopen(input_file_name, "r");
	
	while (!feof(input_file)) { 
		fgets(current_line, sizeof(current_line), input_file);
		
		
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
	
	
	if (program_made){ // Run Program
	
		for (int i = 1; i < program_count+1; i++){
			
			printf("\n\nSnippet %d:\n", i);
			
			
			char command[100];
			snprintf(command, 100, "gcc output%d.c -o NotesProgram.exe", i);
			
			system(command);
			system("NotesProgram.exe");
				
		}
	}
		
	return 0;
}
