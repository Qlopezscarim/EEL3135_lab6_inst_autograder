%% Don't touch this please
autograder_setup = struct('Q1','double','Q2','double','Q3','double','Q4','double','Q5','double','Q6','double','Q7','double','Q8','double','Q9','double','Q10','double');
export_workspace_var(autograder_setup,true,NaN);
%What is this doing?
%It's letting the autograder know to look for these files. Thus, uploading
%these Q1-10 files AND the variables.json file to the github will give you
%feedback on your results
%% part a



H1 = NaN; %what your DTFT function returns for l=10
export_workspace_var("Q1",false,abs(H1));
%% Part b
%length 10




H2 = NaN; %what your DTFT function returns for l=10
export_workspace_var("Q2",false,abs(H2));
%length 100




H3 = NaN; %what your DTFT function returns for l=100
export_workspace_var("Q3",false,abs(H3));
%% part c
%length 10



H4 = NaN; %ditto
export_workspace_var("Q4",false,abs(H4));
%length 100





H5 = NaN; %ditto
export_workspace_var("Q5",false,abs(H5));

%% part d
%length 10



H6 = NaN; %ditto
export_workspace_var("Q6",false,abs(H6));
%length 100




H7 = NaN; %ditto
export_workspace_var("Q7",false,abs(H7));
%% part e
%length 10



H8 = NaN; %ditto
export_workspace_var("Q8",false,abs(H8));
%length 100



H9 = NaN; %ditto
export_workspace_var("Q9",false,abs(H9));
%% Filtering Fun



H10 = NaN; %Should be the frequency response of your FILTERED signal
export_workspace_var("Q10",false,abs(H10));
