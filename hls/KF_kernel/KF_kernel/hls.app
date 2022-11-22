<project xmlns="com.autoesl.autopilot.project" name="KF_kernel" top="KalmanFilterKernel">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../../../src/hls_src/data.h" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="../../../../src/hls_src/kf_test.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="../../src/hls_src/matrix_ops.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../../src/hls_src/KF_kernel.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../../src/hls_src/KF_kernel.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

