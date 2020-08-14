#![no_std]

#[cfg(not(debug_assertions))]
use panic_halt as _;

#[cfg(debug_assertions)]
use panic_semihosting as _;

use cortex_m_rt::ExceptionFrame;
use cortex_m_rt::{exception};

#[exception]
fn HardFault(ef: &ExceptionFrame) -> ! {
    panic!("{:#?}", ef)
}

extern "C" {
    pub fn board_init() -> bool;
    pub fn _tx_initialize_kernel_enter();
}

#[no_mangle]
pub unsafe extern "C" fn rust_main() -> i32 {
    let _ = board_init();
    _tx_initialize_kernel_enter();
    0
}