data = squeeze(out.Poten.signals.values);
time = out.Poten.time;

size = lenght(data);
partlen = floor(size/3);

period1 = data(1:part_len);
period2 = data(part_len+1 : 2*part_len);
period3 = data(2*part_len+1 : end);

mean1 = mean(period1);
mean2 = mean(period2);
mean3 = mean(period3);

means = [mean1, mean2, mean3];
disp(table([mean1; mean2; mean3], 'VariableNames', {'MeanValues'}, 'RowNames', {'Period1','Period2','Period3'}))