Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A008\current_leases.md`
Do not edit `current_leases.md`; read it for current lease status.

Open follow-up:
- Create exact by-memory pages for newly noticed source-looking raw helpers once an approved create-and-lease path or pre-created placeholders exist. A008 lease attempts for both missing target paths were rejected as `File not found`.
  - `0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`: allocates/copies payload and mask spans from a 24-byte frame record into output fields through `GetMemoryMan`, `AllocateBufferMemory`, and `MemmoveWrapper`.
  - `0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`: copies a 16-byte rectangle from a 24-byte frame-record array by index.
  - `0x005b6760-0x005b67c0.SendWearPacket.md`: adjacent raw wear-packet helper documented from `0x005b6560-0x005b6760.WearInputPane.md`; writes opcode `0x1e`, selector byte argument, and sends two bytes through `g_packetSender` / `dword_67A7EC`.
