Signal = squeeze(out.Movingavg.signals.values);
Digital = squeeze(out.Schmitt.signals.values);
time = out.tout;

% Plot the signals for comparison
figure;
plot(time, Signal, 'b', 'DisplayName', 'Moving Average Signal');
hold on;
plot(time, Digital, 'r', 'DisplayName', 'Schmitt Trigger Signal');

% Add constant lines
yline(1100, '--g', 'DisplayName', 'Lower bound', 'LineWidth', 1.2);
yline(2200, '--m', 'DisplayName', 'Upper bound', 'LineWidth', 1.2);

% Labels and title
xlabel('Time (s)');
ylabel('Signal Value');
title('กราฟแสดง Schmitt trigger');
legend show;
hold off;