% --- Data ---
weight = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10];
adc_output = [52.6666667, 162, 304.333333, 444.666667, 589, 736, 876, 1021, 1168.33333, 1320.33333, 1472, 1616, 1766, 1913.33333, 2062.66667, 2210.66667, 2358.66667, 2499.66667, 2646.66667, 2794.66667, 2944];

% --- Find Fits ---
linear_coeffs = polyfit(adc_output, weight, 1);
poly_coeffs = polyfit(adc_output, weight, 2);

% --- Calculate R-squared for BOTH models ---
% 1. Get the predicted y-values from each model
y_predicted_linear = polyval(linear_coeffs, adc_output);
y_predicted_poly = polyval(poly_coeffs, adc_output);

% 2. Calculate the Sum of Squares Total (SST)
sst = sum((weight - mean(weight)).^2);

% 3. Calculate the Sum of Squares Residual (SSE) for each model
sse_linear = sum((weight - y_predicted_linear).^2);
sse_poly = sum((weight - y_predicted_poly).^2);

% 4. Calculate R-squared for each model
r2_linear = 1 - (sse_linear / sst);
r2_poly = 1 - (sse_poly / sst);

% --- Display Equations and R-squared values ---
fprintf('--- Equations and R-squared for Flipped Axes ---\n');
fprintf('Linear Equation:\n');
fprintf('Avg_Weight = (%.6f * ADC_Output) + (%.4f)\n', linear_coeffs(1), linear_coeffs(2));
fprintf('R-squared = %.6f\n\n', r2_linear);

fprintf('Polynomial Equation:\n');
fprintf('Avg_Weight = (%.8f * ADC_Output^2) + (%.6f * ADC_Output) + (%.4f)\n', poly_coeffs(1), poly_coeffs(2), poly_coeffs(3));
fprintf('R-squared = %.6f\n', r2_poly);

% --- Plotting ---
figure; 
hold on;

% Plot original data
plot(adc_output, weight, 'o', 'DisplayName', 'Original Data');

% Create a finer set of x-points for smooth curves
adc_fit = linspace(min(adc_output), max(adc_output), 100);

% Plot the linear fit with its R-squared value in the legend
linear_legend_str = sprintf('Linear Fit (R^2 = %.4f)', r2_linear);
plot(adc_fit, polyval(linear_coeffs, adc_fit), 'r-', 'LineWidth', 1.5, 'DisplayName', linear_legend_str);

% Plot the polynomial fit with its R-squared value in the legend
poly_legend_str = sprintf('Polynomial Fit (R^2 = %.4f)', r2_poly);
plot(adc_fit, polyval(poly_coeffs, adc_fit), 'g--', 'LineWidth', 1.5, 'DisplayName', poly_legend_str);

hold off;

% --- Add labels, title, and legend ---
title('Average Weight vs. ADC Output');
xlabel('ADC Output');
ylabel('Average Weight [Kg]');
grid on;
legend('show', 'Location', 'northwest');