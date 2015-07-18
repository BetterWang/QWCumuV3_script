function ratiopt = ratiopt(m)

	tmp = [m(:,1), m(:,5)./m(:,3), m(:,6)];
	tmp = tmp(2:9,:);
	ratiopt = mean(tmp);

end
