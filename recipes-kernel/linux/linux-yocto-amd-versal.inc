#
# Copyright (C) 2024 Wind River Systems, Inc.
#

COMPATIBLE_MACHINE = "amd-versal"

TARGET_SUPPORTED_KTYPES = "standard preempt-rt"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

KERNEL_DTC_FLAGS:append:amd-versal = " -@"
