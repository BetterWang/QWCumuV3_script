function ratio = ratio(m)

	tmp = [m(:,1), m(:,5)./m(:,3), m(:,6)];
	ratio = mean(tmp);

end
