C = load(sprintf("%s.mat", fname));

str = {
'Ov22pt_120'
'Ov22pt_150'
'Ov22pt_185'
'Ov22pt_220'
'Ov24pt_120'
'Ov24pt_150'
'Ov24pt_185'
'Ov24pt_220'
'Ov26pt_120'
'Ov26pt_150'
'Ov26pt_185'
'Ov26pt_220'
'Ov28pt_120'
'Ov28pt_150'
'Ov28pt_185'
'Ov28pt_220'
'Ov22eta_120'
'Ov22eta_150'
'Ov22eta_185'
'Ov22eta_220'
'Ov24eta_120'
'Ov24eta_150'
'Ov24eta_185'
'Ov24eta_220'
'Ov26eta_120'
'Ov26eta_150'
'Ov26eta_185'
'Ov26eta_220'
'Ov28eta_120'
'Ov28eta_150'
'Ov28eta_185'
'Ov28eta_220'
};


for i = 1:16
	C.(char(str(i))) = C.(char(str(i)))(2:10,:);
end

fid = fopen(sprintf("%s.txt", fname), 'w');
for i = 1:size(str,1)
	mx = C.(char(str(i)));
	fprintf(fid, "%s\n", char(str(i)));
	for rol = 1:size(mx, 1)
		for col = 1:size(mx, 2)
			fprintf(fid, "\t%f\t", mx(rol, col));
			if col != size(mx, 2)
				fprintf(fid, "&");
			end
		end
		fprintf(fid, "\n");
	end
	fprintf(fid, "\n");
end
fclose(fid);
