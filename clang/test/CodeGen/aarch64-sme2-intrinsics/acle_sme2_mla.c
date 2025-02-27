// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme2 -target-feature +sme-f64f64 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme2 -target-feature +sme-f64f64 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sme2 -target-feature +sme-f64f64 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sme2 -target-feature +sme-f64f64 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sme2 -target-feature +sme-f64f64 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
#include <arm_sme_draft_spec_subject_to_change.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED,A5) A1##A3##A5
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4,A5) A1##A2##A3##A4##A5
#endif

//
// Multi, multi
// CHECK-LABEL: @test_svmla2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZM:%.*]], i64 0)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZM]], i64 4)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svmla2_f32j13svfloat32x2_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZM:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZM]], i64 4)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla2_f32(uint32_t slice_base, svfloat32x2_t zn, svfloat32x2_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_za32,_f32,_vg1x2,,)(slice_base, zn, zm);
}

// CHECK-LABEL: @test_svmla4_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM:%.*]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 4)
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 8)
// CHECK-NEXT:    [[TMP7:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 12)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], <vscale x 4 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svmla4_f32j13svfloat32x4_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 4)
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 8)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZM]], i64 12)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], <vscale x 4 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla4_f32(uint32_t slice_base, svfloat32x4_t zn, svfloat32x4_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_za32,_f32,_vg1x4,,)(slice_base, zn, zm);
}

//
// Multi, single
// CHECK-LABEL: @test_svmla_single2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z22test_svmla_single2_f32j13svfloat32x2_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[ZM:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_single2_f32(uint32_t slice_base, svfloat32x2_t zn, svfloat32_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla,_single,_za32,_f32,_vg1x2)(slice_base, zn, zm);
}

// CHECK-LABEL: @test_svmla_single4_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z22test_svmla_single4_f32j13svfloat32x4_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[ZM:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_single4_f32(uint32_t slice_base, svfloat32x4_t zn, svfloat32_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla,_single,_za32,_f32,_vg1x4)(slice_base, zn, zm);
}

//
// Multi, indexed
// CHECK-LABEL: @test_svmla_lane2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[ZM:%.*]], i32 3)
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svmla_lane2_f32j13svfloat32x2_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x2.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[ZM:%.*]], i32 3)
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_lane2_f32(uint32_t slice_base, svfloat32x2_t zn, svfloat32_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_lane_za32,_f32,_vg1x2,,)(slice_base, zn, zm, 3);
}

// CHECK-LABEL: @test_svmla_lane4_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[ZM:%.*]], i32 3)
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svmla_lane4_f32j13svfloat32x4_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x4.nxv4f32(i32 [[SLICE_BASE:%.*]], <vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]], <vscale x 4 x float> [[ZM:%.*]], i32 3)
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_lane4_f32(uint32_t slice_base, svfloat32x4_t zn, svfloat32_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_lane_za32,_f32,_vg1x4,,)(slice_base, zn, zm, 3);
}

//
// Multi, multi
// CHECK-LABEL: @test_svmla2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZM:%.*]], i64 0)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZM]], i64 2)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svmla2_f64j13svfloat64x2_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZM:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZM]], i64 2)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla2_f64(uint32_t slice_base, svfloat64x2_t zn, svfloat64x2_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_za64,_f64,_vg1x2,,)(slice_base, zn, zm);
}

// CHECK-LABEL: @test_svmla4_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM:%.*]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 2)
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 4)
// CHECK-NEXT:    [[TMP7:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 6)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[TMP4]], <vscale x 2 x double> [[TMP5]], <vscale x 2 x double> [[TMP6]], <vscale x 2 x double> [[TMP7]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svmla4_f64j13svfloat64x4_tS_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 2)
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 4)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZM]], i64 6)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[TMP4]], <vscale x 2 x double> [[TMP5]], <vscale x 2 x double> [[TMP6]], <vscale x 2 x double> [[TMP7]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla4_f64(uint32_t slice_base, svfloat64x4_t zn, svfloat64x4_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_za64,_f64,_vg1x4,,)(slice_base, zn, zm);
}

//
// Multi, single
// CHECK-LABEL: @test_svmla_single2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z22test_svmla_single2_f64j13svfloat64x2_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[ZM:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_single2_f64(uint32_t slice_base, svfloat64x2_t zn, svfloat64_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla,_single,_za64,_f64,_vg1x2)(slice_base, zn, zm);
}

// CHECK-LABEL: @test_svmla_single4_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z22test_svmla_single4_f64j13svfloat64x4_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.single.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[ZM:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_single4_f64(uint32_t slice_base, svfloat64x4_t zn, svfloat64_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla,_single,_za64,_f64,_vg1x4)(slice_base, zn, zm);
}

//
// Multi, indexed
// CHECK-LABEL: @test_svmla_lane2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[ZM:%.*]], i32 1)
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svmla_lane2_f64j13svfloat64x2_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x2.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[ZM:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_lane2_f64(uint32_t slice_base, svfloat64x2_t zn, svfloat64_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_lane_za64,_f64,_vg1x2,,)(slice_base, zn, zm, 1);
}

// CHECK-LABEL: @test_svmla_lane4_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[ZM:%.*]], i32 1)
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svmla_lane4_f64j13svfloat64x4_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv8f64(<vscale x 8 x double> [[ZN]], i64 6)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sme.fmla.lane.vg1x4.nxv2f64(i32 [[SLICE_BASE:%.*]], <vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x double> [[TMP2]], <vscale x 2 x double> [[TMP3]], <vscale x 2 x double> [[ZM:%.*]], i32 1)
// CPP-CHECK-NEXT:    ret void
//
void test_svmla_lane4_f64(uint32_t slice_base, svfloat64x4_t zn, svfloat64_t zm) __arm_streaming __arm_shared_za {
  SVE_ACLE_FUNC(svmla_lane_za64,_f64,_vg1x4,,)(slice_base, zn, zm, 1);
}
