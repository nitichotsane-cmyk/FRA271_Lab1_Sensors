% โหลดข้อมูลจากไฟล์ .mat โดยเก็บไว้ในโครงสร้าง (struct)
try
    data_struct = load('Encoder_1_1.mat');

    % ดึงชื่อตัวแปรทั้งหมดที่อยู่ในไฟล์
    variable_names = fieldnames(data_struct);

    % โดยทั่วไปไฟล์ลักษณะนี้จะมี Dataset object อยู่เพียงตัวเดียว
    % เราจะใช้ตัวแปรตัวแรกที่เจอในไฟล์
    dataset_object = data_struct.(variable_names{1});

    % --- ดึงข้อมูลสัญญาณจาก Dataset object ที่หาเจอ ---
    signal_x1 = dataset_object.get('Homing1:1');
    signal_x2 = dataset_object.get('Homing4:1');
    signal_x4 = dataset_object.get('Homing5:1');

    % ดึงข้อมูลเวลา (Time) และค่า (Data) ของแต่ละสัญญาณ
    time_x1 = signal_x1.Values.Time;
    data_x1 = signal_x1.Values.Data;

    time_x2 = signal_x2.Values.Time;
    data_x2 = signal_x2.Values.Data;

    time_x4 = signal_x4.Values.Time;
    data_x4 = signal_x4.Values.Data;

    % --- สร้างกราฟ (ส่วนนี้เหมือนเดิม) ---
    figure;
    hold on;

    plot(time_x1, data_x1, 'LineWidth', 1.5);
    plot(time_x2, data_x2, 'LineWidth', 1.5);
    plot(time_x4, data_x4, 'LineWidth', 1.5);

    hold off;

    title('Encoder Signals (X1, X2, X4)', 'FontSize', 14);
    xlabel('Time (seconds)', 'FontSize', 12);
    ylabel('Encoder Value', 'FontSize', 12);
    legend('Encoder X4', 'Encoder X2', 'Encoder X1');
    grid on;
    axis tight;

catch ME
    % แสดงข้อผิดพลาดที่เกิดขึ้น
    disp('เกิดข้อผิดพลาดในการประมวลผลไฟล์:');
    disp(ME.message);
    disp('กรุณาตรวจสอบว่าไฟล์ .mat ไม่ได้เสียหายและมีสัญญาณที่ระบุครบถ้วน');
end