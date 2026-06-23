*This project has been created as part of the 42 curriculum by [your_login].*

<div align="center">

# 🌐 NetPractice

### A TCP/IP Networking Configuration Project — 42 School

![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Network](https://img.shields.io/badge/Topic-Networking-blue?style=for-the-badge)
![Level](https://img.shields.io/badge/Levels-10-green?style=for-the-badge)
![Language](https://img.shields.io/badge/Interface-Browser-orange?style=for-the-badge)

</div>

---

## 📋 Table of Contents

- [Description](#-description)
- [Networking Concepts](#-networking-concepts-covered)
- [Level Overview](#-level-overview)
- [Instructions](#-instructions)
- [Key Rules & Tips](#-key-rules--tips)
- [Resources](#-resources)

---

## 📖 Description

**NetPractice** is a system administration and networking project from the 42 curriculum. Its goal is to make you comfortable with **TCP/IP network configuration** through hands-on practice in a browser-based training interface.

You are presented with **10 levels**, each showing a small network topology with misconfigured or incomplete settings. Your task is to identify and fix every address, subnet mask, gateway, and routing table entry so that all hosts in the network can communicate correctly.

This project does not require any programming. Instead, it challenges your understanding of how networks are structured, how packets travel from one host to another, and how routers make forwarding decisions. Each level is progressively more complex, introducing additional subnets, routers, and routing constraints.

By completing NetPractice, you will be able to:

- Read and interpret a network diagram
- Calculate valid IP address ranges from a subnet mask or CIDR prefix
- Avoid common mistakes (overlapping subnets, wrong gateways, missing routes)
- Configure routing tables with correct destination/mask/next-hop entries
- Reason about reachability between any two hosts in a topology

---

## 🧠 Networking Concepts Covered

### 🔷 The OSI Model

The OSI (Open Systems Interconnection) model describes how data travels across a network in 7 layers. NetPractice focuses primarily on:

| Layer | Name | Role in NetPractice |
|-------|------|---------------------|
| 2 | Data Link | MAC addressing, switches, same-subnet delivery |
| 3 | Network | IP addressing, routing, subnet masks |

Understanding these layers explains *why* a host needs a default gateway (it cannot send packets directly to another subnet without help from a router at Layer 3), and *why* two devices on the same subnet can communicate directly via a switch at Layer 2.

---

### 🔷 IPv4 Addressing

An IPv4 address is a 32-bit number written in **dotted-decimal notation**, divided into 4 octets of 8 bits each:

```
192.168.1.10
└─┬─┘└─┬─┘└┬┘└┬┘
  |    |   |   └── Host part
  |    |   └────── Host part
  |    └────────── Network part (depends on mask)
  └─────────────── Network part (depends on mask)
```

The **subnet mask** (or CIDR prefix) defines where the network portion ends and the host portion begins.

---

### 🔷 Subnet Masks & CIDR Notation

A subnet mask is also a 32-bit number. All network bits are `1`, all host bits are `0`.

| CIDR | Subnet Mask | # Hosts | Binary |
|------|-------------|---------|--------|
| /24 | 255.255.255.0 | 254 | `11111111.11111111.11111111.00000000` |
| /25 | 255.255.255.128 | 126 | `11111111.11111111.11111111.10000000` |
| /26 | 255.255.255.192 | 62 | `11111111.11111111.11111111.11000000` |
| /27 | 255.255.255.224 | 30 | `11111111.11111111.11111111.11100000` |
| /28 | 255.255.255.240 | 14 | `11111111.11111111.11111111.11110000` |
| /30 | 255.255.255.252 | 2 | `11111111.11111111.11111111.11111100` |

> ⚠️ Always subtract 2 from the host count: one address is reserved for the **network address** (all host bits = 0) and one for the **broadcast address** (all host bits = 1).

**Example — calculating a subnet range:**

```
IP address  : 192.168.1.65
Subnet mask : 255.255.255.192  (/26)

Network address   : 192.168.1.64    ← First address (not assignable)
First usable host : 192.168.1.65
Last usable host  : 192.168.1.126
Broadcast address : 192.168.1.127   ← Last address (not assignable)
```

---

### 🔷 Private Address Ranges (RFC 1918)

The following address blocks are reserved for private (non-routable) use on internal networks:

| Range | CIDR | Addresses |
|-------|------|-----------|
| `10.0.0.0` – `10.255.255.255` | `10.0.0.0/8` | ~16 million |
| `172.16.0.0` – `172.31.255.255` | `172.16.0.0/12` | ~1 million |
| `192.168.0.0` – `192.168.255.255` | `192.168.0.0/16` | ~65,000 |

> ⚠️ The range `127.0.0.0/8` (loopback) is also reserved and must **never** be assigned to a network interface.

---

### 🔷 Network Address & Broadcast Address

Within any subnet, two addresses are always reserved and **cannot be assigned to a host**:

- **Network address** — the first address in the range (all host bits are 0). It identifies the subnet itself.
- **Broadcast address** — the last address in the range (all host bits are 1). Packets sent to this address are delivered to every host on the subnet.

```
Subnet: 192.168.0.0/28

Network address   : 192.168.0.0   ✗ cannot assign
Usable hosts      : 192.168.0.1  →  192.168.0.14
Broadcast address : 192.168.0.15  ✗ cannot assign
```

---

### 🔷 Default Gateway

A **default gateway** is the IP address of the router interface on the local subnet. When a host wants to send a packet to a destination outside its own subnet, it forwards the packet to its gateway, which then routes it onward.

Rules:
- The gateway address **must be on the same subnet** as the host.
- It is typically the first or last usable address in the subnet (by convention, not requirement).
- If no gateway is configured, the host can only reach devices on its own subnet.

---

### 🔷 Routers & Routing Tables

A **router** connects multiple networks and forwards packets between them based on a **routing table**.

Each entry in a routing table has three fields:

| Field | Description |
|-------|-------------|
| **Destination** | The target network (e.g., `192.168.1.0`) |
| **Mask** | The subnet mask for the destination (e.g., `/24`) |
| **Next hop** | The IP of the next router (or `0.0.0.0` if directly connected) |

When a packet arrives, the router performs a **longest prefix match** — it looks for the routing entry whose destination/mask most specifically matches the packet's destination IP.

The special entry `0.0.0.0/0` is the **default route**: it matches any destination not covered by a more specific rule, and is used to forward unknown traffic to the internet or upstream router.

---

### 🔷 Switches

A **switch** operates at Layer 2 (Data Link). It connects multiple hosts within the **same subnet** and forwards traffic based on MAC addresses. In NetPractice, switches are transparent — you do not configure them directly. They simply allow multiple hosts to share the same network segment.

> A switch does **not** route between subnets. Only routers do.

---

## 📊 Level Overview

| Level | Key Concept Introduced |
|-------|------------------------|
| 1 | Basic IP address assignment — same subnet, no router |
| 2 | Subnet mask consistency between two hosts |
| 3 | Multi-host subnet with correct address ranges |
| 4 | Router with two interfaces on different subnets |
| 5 | Default gateway configuration on hosts |
| 6 | Internet-facing routing with a default route |
| 7 | Multiple routers — routing table with next-hop |
| 8 | Complex topology with overlapping constraints |
| 9 | Multi-subnet routing with several routers |
| 10 | Full topology combining all previous concepts |

---

## 🚀 Instructions

### Prerequisites

- A modern web browser (Chrome, Firefox, Safari, Edge)
- No additional software installation required

### Step 1 — Clone the Repository

```bash
git clone https://github.com/<your_login>/NetPractice.git
cd NetPractice
```

### Step 2 — Launch the Training Interface

Run the provided script to start the local server:

```bash
bash run.sh
```

Then open your browser and go to the URL displayed in the terminal. You will see the NetPractice interface with level selection.

> **Note:** If `run.sh` does not execute, check permissions with `chmod +x run.sh` and try again.

### Step 3 — Solve Each Level

1. Read the network diagram carefully.
2. Identify which fields are editable (shown in white/input boxes).
3. Fill in the correct IP addresses, subnet masks, gateway addresses, and routing table entries.
4. Click **"Check again"** to validate your configuration.
5. A success message confirms you have solved the level.

### Step 4 — Export Your Configuration

Once a level is solved:

1. Click the **"Get my config"** button.
2. A `.json` file will be downloaded to your machine.
3. Rename it if needed to match the expected filename (e.g., `level1.json`).

Repeat for all 10 levels.

### Step 5 — Submit

Place all 10 exported `.json` files at the **root of your Git repository**:

```
NetPractice/
├── README.md
├── level1.json
├── level2.json
├── level3.json
├── level4.json
├── level5.json
├── level6.json
├── level7.json
├── level8.json
├── level9.json
└── level10.json
```

Commit and push before your submission deadline:

```bash
git add *.json README.md
git commit -m "feat: add all 10 NetPractice level configurations"
git push origin main
```

---

## 💡 Key Rules & Tips

### ✅ Things to always check

- Two hosts on the same subnet must have the **same network address** (same IP & mask combination pointing to the same network).
- A host's **default gateway must be on its own subnet**.
- Router interfaces connecting two subnets must each have an address in **their respective subnet** — they are not on the same subnet as each other.
- Each subnet must be **unique** — no two different network segments can share the same address range.
- The routing table of a router must have a route for every destination it needs to reach, either explicit or via a default route (`0.0.0.0/0`).

### ❌ Common mistakes

| Mistake | Why it breaks |
|---------|---------------|
| Assigning the network address (e.g., `.0`) to a host | Network address is not usable |
| Assigning the broadcast address (e.g., `.255`) to a host | Broadcast address is not usable |
| Gateway not on the same subnet as the host | Host cannot reach the gateway |
| Two subnets with overlapping ranges | Router cannot distinguish which interface to use |
| Missing return route in a router's table | Packets arrive but responses never return |
| Using `127.x.x.x` addresses | Loopback range, reserved |

### 🧮 Quick Subnet Cheatsheet

```
/30  →  mask 255.255.255.252  →  2 usable hosts
/29  →  mask 255.255.255.248  →  6 usable hosts
/28  →  mask 255.255.255.240  →  14 usable hosts
/27  →  mask 255.255.255.224  →  30 usable hosts
/26  →  mask 255.255.255.192  →  62 usable hosts
/25  →  mask 255.255.255.128  →  126 usable hosts
/24  →  mask 255.255.255.0    →  254 usable hosts
```

---

## 📚 Resources

### Official & Reference Documentation

- [RFC 791 — Internet Protocol (IPv4 Specification)](https://www.rfc-editor.org/rfc/rfc791)
- [RFC 1918 — Address Allocation for Private Internets](https://www.rfc-editor.org/rfc/rfc1918)
- [RFC 4632 — Classless Inter-Domain Routing (CIDR)](https://www.rfc-editor.org/rfc/rfc4632)
- [Cisco — IP Addressing and Subnetting Guide](https://www.cisco.com/c/en/us/support/docs/ip/routing-information-protocol-rip/13788-3.html)

### Learning Resources

- [Cloudflare Learning Center — What is a Subnet?](https://www.cloudflare.com/learning/network-layer/what-is-a-subnet/)
- [Cloudflare — What is a Router?](https://www.cloudflare.com/learning/network-layer/what-is-a-router/)
- [Professor Messer — Subnetting (YouTube)](https://www.youtube.com/watch?v=EkNq4TrHP_U)
- [PowerCert — Subnet Mask Explained (YouTube)](https://www.youtube.com/watch?v=s_Ntt6eTn94)
- [Wikipedia — OSI Model](https://en.wikipedia.org/wiki/OSI_model)
- [Wikipedia — Classless Inter-Domain Routing](https://en.wikipedia.org/wiki/Classless_Inter-Domain_Routing)
- [OpenClassrooms — Understand the TCP/IP Model](https://openclassrooms.com/en/courses/6944606-understand-the-tcp-ip-model)
- [TutorialsPoint — Computer Network Tutorial](https://www.tutorialspoint.com/computer_networking/index.htm)

### Tools

- [ipcalc — IP/Subnet Calculator](https://ipcalc.net/)
- [Subnet Calculator — subnet-calculator.com](https://www.subnet-calculator.com/)
- [CIDR.xyz — Visual CIDR Notation Explorer](https://cidr.xyz/)
- [Visual Subnet Calculator](https://www.davidc.net/sites/default/subnets/subnets.html)

### Networking Concepts Studied

The following topics were studied and applied throughout this project:

| Concept | Description |
|---------|-------------|
| **TCP/IP Addressing** | IPv4 address structure, 32-bit dotted-decimal notation, host vs network identification |
| **Subnet Masks** | Binary interpretation of masks, CIDR prefix length, splitting address space into subnets |
| **Network & Broadcast Addresses** | Reserved first and last addresses in any subnet; must not be assigned to hosts |
| **Default Gateways** | Required for inter-subnet communication; must be on the host's own subnet |
| **Routers** | Layer 3 devices forwarding packets between subnets using routing tables |
| **Switches** | Layer 2 devices connecting hosts on the same subnet via MAC addressing |
| **Routing Tables** | Destination/mask/next-hop entries; longest prefix match; default route `0.0.0.0/0` |
| **OSI Model** | Layered architecture; Layer 2 (Data Link) for local delivery, Layer 3 (Network) for routing |
| **Private Address Ranges** | RFC 1918 ranges: `10.0.0.0/8`, `172.16.0.0/12`, `192.168.0.0/16` |
| **CIDR Notation** | Expressing subnet mask as a prefix length (e.g., `/24` instead of `255.255.255.0`) |

### AI Usage

**Tool used:** Claude (Anthropic)

AI assistance was used during this project in the following ways:

| Task | How AI was used |
|------|-----------------|
| **Concept clarification** | Asked detailed questions about how routing table lookups work (longest prefix match), and how to determine whether two hosts are on the same subnet |
| **Subnet calculations** | Used AI to verify manual subnet calculations (network address, broadcast address, usable range) before entering values in the interface |
| **Debugging stuck levels** | Described topology configurations to AI and asked it to identify which element was misconfigured and why |
| **Understanding routing** | Asked AI to explain the difference between a directly connected route and a next-hop route, and when each applies in NetPractice |
| **README writing** | Used AI to structure, expand, and format this README file to meet the 42 project documentation requirements |

> AI was **not** used to directly produce or export any of the 10 level configuration files. Every network topology was analyzed and solved manually through the training interface.
