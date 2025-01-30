# RISCV-MICRO-OS
## ➡️ Quick Start
Download OpenSBI Firmware
```bash
$ curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin
```

Build and Run Docker Image
```bash
$ docker build -t riscv-micro-os .
$ ./docker.sh
```

Run the Operating System
```bash
$ ./run.sh
```

## 📚 References
- [RISC-V SBI specification](https://github.com/riscv-non-isa/riscv-sbi-doc)