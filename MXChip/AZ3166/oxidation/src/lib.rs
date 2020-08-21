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
    pub fn screen_print(msg:*const u8, line: i32);
}
/*typedef enum {
    L0 = 0,
    L1 = 18,
    L2 = 36,
    L3 = 54
  } LINE_NUM;*/

#[no_mangle]
pub unsafe extern "C" fn rust_main() -> i32 {
    let _ = board_init();
    screen_print(b"Honey Honey!\0".as_ptr(), 0);
    for _i in 0..100000 {}
    screen_print(b"Hi Honey!\0".as_ptr(), 18);
    for _i in 0..100000 {}
    screen_print(b"I LOVE YOU\0".as_ptr(), 36);
    _tx_initialize_kernel_enter();
    0
}