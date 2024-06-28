function export_workspace_var(to_export,first_iteration,value_to_export)
    %THIS IS NOT GOOD CODE DO NOT EVER REFERENCE THIS FOR GOOD CODING
    %STANDARDS
    if first_iteration == true
        jsonStr = jsonencode(to_export);
        filename = 'variables.json';
        fid = fopen(filename, 'w');
        if fid == -1
            error('Cannot open variables.json for writing.');
        end
        fprintf(fid, '%s', jsonStr);
        fclose(fid);
    else
        filename = to_export;
        fid = fopen(filename, 'w');
        if fid == -1
            error('Cannot open variables.json for writing.');
        end
        if isa(value_to_export,'double')
            fprintf(fid,'%f\n',value_to_export);
        elseif isa(value_to_export,'int8') || isa(value_to_export,'int16') || isa(value_to_export,'int32')
            fprintf(fid,'%d\n',value_to_export);
        else
            disp("Not a recognized data type - autograder will not work!")
        end
        fclose(fid);
    end
end