<project xmlns="com.autoesl.autopilot.project" top="KalmanFilterKernel" name="different_Kalman">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../src/kalman_2/vitis/kf_test.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="../../src/hls_src/data.h" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="src/kalman_2/vitis/matrix_ops.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="src/kalman_2/vitis/KF_kernel.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="src/kalman_2/vitis/KF_kernel.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

