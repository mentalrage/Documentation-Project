*** UID:0000V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Packet Digest Helper - 0x00515380

## Status

- Confidence: strong for behavior; medium for final signature.
- Proposed owner: [UID:0000L6][MD5](by-file/MD5.md), not [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- Memory range: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- Evidence basis: IDA MCP xref/decompile checks and `simroot_v2/class_Socket.cpp` on 2026-05-24. `wave3.py` was not executed for this pass.

## Function Role

`0x00515380` is the packet-facing one-shot MD5 helper. It hashes a byte buffer, finalizes the digest, and returns raw digest bytes to `Socket::BuildEncryptedPacket`.

The packet code does not use the full hex digest. It inserts digest bytes `[13]`, `[3]`, `[11]`, and `[7]` into the encrypted packet trailer, followed by the obfuscated packet nonce/key bytes.

## Evidence

- IDA lookup identifies `0x00515380` as function `sub_515380`, size `0x5c`, ending at `0x005153dc`.
- IDA callers show one caller: `Socket::BuildEncryptedPacket` at `0x00578c40`.
- The function initializes the standard MD5 state constants, calls `Md5Update` at `0x00515690`, calls `Md5Final` at `0x00515750`, then returns digest bytes.
- Generated `simroot_v2/class_Socket.cpp` names the helper `ComputePacketDigest` and consumes offsets `13`, `3`, `11`, and `7`.
- IDA MCP recheck on 2026-05-31 confirms `sub_515380` range `0x00515380-0x005153dc`, the single caller in `0x00578c40`, and callees `0x00515690`, `0x00515750`, and the compiler security-cookie check.

## Ownership Decision

Keep this helper in the shared [UID:0000L6][MD5](by-file/MD5.md) module. `PacketTransform` owns the handshake/key-table setup and repeated-key XOR primitive, but the digest implementation is shared algorithm code with callers outside the socket transform path.

## Rewrite Notes

- The current decompilation suggests a pointer to transient digest storage. Do not blindly preserve that unsafe-looking lifetime in final C++ without checking the exact stack/register behavior.
- A caller-provided 16-byte output buffer or a small returned digest object may be the safer reconstruction signature, but final signature choice must preserve `Socket::BuildEncryptedPacket` byte selection exactly.
- Keep the generated `ComputePacketDigest` name only as a packet-context alias; the underlying function should use an MD5-specific name in the utility module.

## Cross-References

- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/75` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the packet digest helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks the helper as rebuild-relevant code while staying conservative because the final signature/lifetime model is still open.
  - Evidence: IDA MCP confirms the exact range, sole `Socket::BuildEncryptedPacket` caller, and MD5 update/final callees.
