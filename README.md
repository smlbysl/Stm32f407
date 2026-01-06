Arhictecture Example 

APPLICATION
│
├── System                      ← çekirdek / global altyapı
│   ├── system_init.c           ← reset sonrası giriş noktası
│   ├── clock.c / clock.h       ← RCC policy (PLL, prescaler)
│   ├── nvic.c / nvic.h         ← interrupt altyapısı
│   ├── systick.c / systick.h   ← system tick
│   └── power.c                 ← low-power / reset
│
├── Drivers                     ← peripheral-odaklı katman
│   │
│   ├── rcc                     ← RCC low-level erişim
│   │   ├── rcc_ll.h            ← RCC register helpers
│   │   └── rcc_ll.c            ← (opsiyonel)
│   │
│   ├── gpio
│   │   ├── gpio.c              ← GPIO public API
│   │   ├── gpio.h
│   │   ├── gpio_ll.h           ← GPIO register seviyesi
│   │   ├── gpio_hw.h           ← donanım detayları
│   │   ├── gpio_cfg.h          ← compile-time config
│   │   ├── gpio_types.h
│   │   └── gpio_isr.h          ← (varsa)
│   │
│   ├── exti
│   │   ├── exti.c              ← EXTI public API
│   │   ├── exti.h
│   │   ├── exti_ll.h           ← EXTI register seviyesi
│   │   ├── exti_cfg.h
│   │   └── exti_isr.h
│   │
│   └── uart / spi / tim / ...
│
└── Device                      ← MCU’ya özgü tanımlar
    └── memmap
        ├── stm32f407xx.h
        ├── stm32f407xx_gpio.h
        ├── stm32f407xx_rcc.h
        ├── stm32f407xx_exti.h
        └── stm32f407xx_* .h
