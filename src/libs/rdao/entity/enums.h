#pragma once

namespace Rt
{
	enum Status {
		Normal,
		Service,
		Frozen,
		Deleted
	};

	enum MachineStatus {
		Idle,
		Running,
		Service,
		Forbidden
	};

	enum Gender {
		Male,
		Female,
		Unknown
	};

	enum Role {
		Admin = 1,
		HeadNurse,
		OpUser,
		ClinicUser,
		Unknown
	};

	enum ReaderCategory {
		Flow,
		Machine,
		PC,
		Other
	};

	enum EndoscopeCategory {
		Normal,
		HighRisk,
		Unknown
	};

	enum MachineProgramCategory {
		Unknown
	};

	enum MachineCategory {
		WithDry,
		NoDry,
		Unknown
	};

	enum FluidCategory {
		Clean,
		Disinfect
	};

	enum DisinfectCategory {
		OneOFF,
		Reuse,
		Unknown
	};

	enum FlowStatus {
		Unknown,
		Bind,
		Leak,
		Wash,
		Rinse,
		InMachine,
		Sterilize, 
		EndingRinse,
		Dry,
		Storage,
		Use,
		PreProcessing,
		Recalled = 99
	};

	enum Verdict{
		Default,
		Qualified,
		Unqualified,
		Uninvolved
	};
}
