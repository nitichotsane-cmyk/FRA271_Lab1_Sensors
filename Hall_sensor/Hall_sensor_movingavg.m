movingavg = squeeze(out.Magmoving.signals.values);
rawsignal = squeeze(out.Magmoving.signals.values);
time = out.tout;

% Cut the signals only between t = 10 and t = 25
cutIndices = time >= 10 & time <= 18;
timeCut = time(cutIndices);
movingavgCut = movingavg(cutIndices);
rawsignalCut = rawsignal(cutIndices);

figure;
plot(timeCut, rawsignalCut,'LineWidth',2);
hold on;
plot(timeCut, movingavgCut,'LineWidth',2);
hold off;
title('Sample of Signal after Moving Average Filter');
xlabel('Time (ms)');
ylabel('Signal Amplitude');
legend('Raw Signal', 'Moving Average Filter');